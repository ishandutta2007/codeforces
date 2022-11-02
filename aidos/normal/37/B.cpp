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
int n, p[2222], d[2222], b[2222], ma, ti;
vector < pii > v;
bool check(int m, int r, int t, int z){
	if(m <= 0){
		ti = t;
		return 1;
	}
	int k = -1, mm = -1;
	for(int i = 0; i<n; i++){
		if(b[i] && m*100<=p[i]*ma && mm < d[i]){
			k = i;
			mm = d[i];
		}
	}
	if(k != -1){
		b[k] = 0;
		z+=d[k];
		if(check(min(m+r-z, ma), r, t+1, z)){
			v.pb(mp(t, k+1));
			return 1;
		}
		return 0;
	}
	else {
		if(r >= z) return 0;
		return check(min(m + r - z, ma), r, t+1, z);
	}
}
int main () {
	int m, r;
	cin >> n >> m >> r;
	for(int i = 0; i<n; i++){
		cin >> p[i] >> d[i];
		b[i] = 1;
	}
	ma = m;
	if(check(m, r, 0, 0) == 0) cout << "NO";
	else {
		cout << "YES" << endl;
		cout << ti << " " << v.size() << endl;
		sort(v.begin(), v.end());
		for(int i = 0; i<v.size(); i++)
			cout << v[i].ff << " " << v[i].sc << endl;
	}
    return 0;
}