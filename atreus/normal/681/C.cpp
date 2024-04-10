#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>

#define F first
#define S second

using namespace std;

multiset <int> s; 
vector <pair <string, int> > v;

int main (){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		string a;
		cin >> a;
		if (a == "removeMin"){
			if (s.empty())
				v.push_back(make_pair("insert", 1));
			else {
				set<int>::iterator it = s.begin();
				s.erase(it);
			}
			v.push_back(make_pair("removeMin", 1));
		}
		else {
			int b;
			cin >> b;
			if (a == "insert"){
				s.insert(b);
				v.push_back(make_pair("insert", b));
			}
			else {
				if (s.find(b) == s.end()){
					v.push_back(make_pair("insert", b));
					s.insert(b);
				}
				set<int>::iterator it = s.lower_bound(b);
				while (s.lower_bound(b) != s.begin()){
					v.push_back(make_pair("removeMin", 0));
					s.erase(s.begin());
				}
				v.push_back(make_pair("getMin", b));
			}
		}
	}
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++){
		cout << v[i].first << " ";
		if (v[i].first != "removeMin")
			cout << v[i].second;
		cout << endl;
	}
}