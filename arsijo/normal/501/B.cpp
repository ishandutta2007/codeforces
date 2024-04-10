/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

struct person{
	string s1, s2;
};

vector<person> nicks;

void add(string s1, string s2){
	for(int i = 0; i < nicks.size(); i++){
		if (nicks[i].s2 == s1){
			nicks[i].s2 = s2;
			return;
		}
	}
	person newPerson;
	newPerson.s1 = s1;
	newPerson.s2 = s2;
	nicks.insert(nicks.end(), newPerson);
}

int main() {

	//freopen("c.in", "r", stdin); freopen("c.out", "w", stdout);
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		string s1, s2;
		cin >> s1 >> s2;
		add(s1, s2);
	}

	cout << nicks.size() << endl;
	for(int i = 0; i < nicks.size(); i++){
		cout << nicks[i].s1 << " " << nicks[i].s2 << endl;
	}

}