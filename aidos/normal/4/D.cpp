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
	vector < pair < pii, int> > v;
	int n, x, y, z, t, d[100111], k = 0, p[100111];
	cin >> n >> z >> t;
	for(int i = 0; i<n; i++){
		cin >> x >> y;
		if(x >z && y>t){
			v.pb(mp(mp(x, y), i));
		}
	}
	sort(v.begin(), v.end());
	memset(d, 0, sizeof(d));
	memset(p, -1, sizeof(p));
	n = v.size();
	if(n == 0){
		cout << 0;
		return 0;
	}
	for(int i = 0; i < n; i++){
		d[i] = 1;
		for(int j = 0; j<i; j++){
			if(v[i].ff.ff>v[j].ff.ff && v[i].ff.sc > v[j].ff.sc){
				if(d[j] >= d[i]){
					d[i] = d[j] + 1;
					p[i] = j;
				}
			}
		}
		if(d[i]> d[k]) k = i;
	}
	cout << d[k] << endl;
	vector < int > u;
	p[100011] = k;
	k = 100011;
	do{
		k = p[k];
		u.pb(v[k].sc);
	}
	while(p[k] != -1);
	reverse(u.begin(), u.end());
	for(vector < int > :: iterator it = u.begin(); it!=u.end(); it++)
		cout << *it+1 << " ";
    return 0;
}