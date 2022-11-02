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
	string s, t;
	cin >> s;
	int k = 1, x = s.size();
	vector < pii > v;
	for(int i = 1; i<x; i++){
		if(s[i] != s[i-1]){
			v.pb(mp(s[i-1], k));
			k = 1;
		}
		else {
			k++;
		}
	}
	v.pb(mp(s[x-1], k));
	int l = v.size();
	for(int i = min(v[0].sc, 2); i>0; i--)
		cout <<( (char)v[0].ff);
	for(int i = 1; i<l; i++){
		if(v[i].sc>1){
			if(v[i-1].sc>1){
				cout << ((char) (v[i].ff));
				v[i].sc=1;
			}
			else {
				cout << ((char) (v[i].ff));
				cout << ((char) (v[i].ff));
			}
		}
		else {     
			cout << ((char) (v[i].ff));
		}
	}
	return 0;
}