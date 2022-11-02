#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define sc second
#define pii pair<int,int>
#define pis pair<int, string>
#define psi pair<string, int>
using namespace std;
int main () {
	int n;
	cin >> n;
	vector < string > v;
	for(int i = 0; i<n; i++){
		string s;
		cin >> s;
		if(s == "pwd"){
			cout << "/";
			for(int j = 0; j<v.size(); j++) cout << v[j] << "/";
			cout << endl;
		}
		else {
			string t;
			cin >> t;
			int f = 0;
			if(t[0] == '/'){
				v.clear();
				f = 1;
			}
			string x = "";
			for(int j = f; j<t.size(); j++){
				if(t[j] == '/'){
					if(x == ".."){
						v.pop_back();
					}
					else v.pb(x);
					x = "";
				}
				else {
					x+=t[j];
				}
			}
			if(x != ""){
				if(x == "..") v.pop_back();
				else v.push_back(x);
			}
		}
	}
    return 0;
}