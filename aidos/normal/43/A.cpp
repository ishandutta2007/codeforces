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
	map < string, int > m;
	vector < string > v;
	for(int i = 0; i<n; i++){
		string s;
		cin >> s;
		if(m[s] == 0) v.pb(s);
		m[s]++;
	}
	if(v.size()==1) cout << v[0];
	else if(m[v[0]] > m[v[1]]) cout << v[0];
	else cout << v[1];
	return 0;
}