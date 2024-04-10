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
	vector < int > v[111111];
	vector < pii > u;
	int n, a;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a;
		v[a].pb(i);
	}
	for(int i = 1; i<100010; i++){
		if(v[i].size() == 1) u.pb(mp(i, 0));
		if(v[i].size() < 2) continue;
		int l=v[i][1]-v[i][0], ok = 1, x = v[i].size();
		for(int j = 2; j<x; j++)
			if(v[i][j] - v[i][j-1] != l){
				ok = 0;
				break;
			}
		if(ok){
			u.pb(mp(i, l));
		}
	}
	int z = u.size();
	cout << z << endl;
	for(int i = 0; i<z; i++)
		cout << u[i].ff << " " << u[i].sc << endl;
    return 0;
}