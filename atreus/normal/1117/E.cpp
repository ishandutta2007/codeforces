/**
 *    author:  Atreus
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;

string ask(string s){
	cout << "? " << s << endl;
	string ret;
	cin >> ret;
	return ret;
}

bool mark[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	string t;
	cin >> t;
	int n = t.size();
	string query;
	for (int i = 0; i < n; i++)
		query += char((i % 26) + 'a');
	string q1 = ask(query);
	query = "";
	for (int i = 0; i < n; i++){
		int x = i / 26;
		query += char((x % 26) + 'a');
	}
	string q2 = ask(query);
	query = "";
	for (int i = 0; i < n; i++){
		int x = i / 26;
		x = x / 26;
		query += char((x % 26) + 'a');
	}
	string q3 = ask(query);
	string s;
	for (int i = 0; i < n; i++){
		memset(mark, 1, sizeof mark);
		int x = i;
		for (int j = 0; j < n; j++)
			if (q1[j] != char((x % 26) + 'a'))
				mark[j] = 0;
		x = x / 26;
		for (int j = 0; j < n; j++)
			if (q2[j] != char((x % 26) + 'a'))
				mark[j] = 0;
		x = x / 26;
		for (int j = 0; j < n; j++)
			if (q3[j] != char((x % 26) + 'a'))
				mark[j] = 0;
		for (int j = 0; j < n; j++)
			if (mark[j] == 1)
				s += t[j];
	}
	cout << "! " << s << endl;
}