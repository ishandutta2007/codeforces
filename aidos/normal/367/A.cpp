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
int a[200000], b[200000], c[200000];
void solve(int l, int r){
		if(r - l + 1 < 3){
			printf("YES\n");
			return;
		}
		vector < int > v;
		v.pb(a[r]-a[l-1]);
		v.pb(b[r]-b[l-1]);
		v.pb(c[r]-c[l-1]);
		int ok = 0;
		for(int j = 0; j<3; j++){
			if(abs(v[j]-v[(j+1)%3]) <= 1){
				ok++;				
			}
		}
		if(ok==3) printf("YES\n");
		else printf("NO\n");
}
int main () {
	string s;
	cin >> s;
	int n = s.size();
	a[0] = b[0] = c[0] = 0;
	for(int i = 1; i<=n; i++){
		a[i] = a[i-1];
		b[i] = b[i-1];
		c[i] = c[i-1];
		if(s[i-1] == 'x') a[i]++;
		else if(s[i-1] == 'y') b[i] ++;
		else if(s[i-1] == 'z') c[i]++;
	}
	int m;
	cin >> m;
	for(int i = 0; i<m; i++){
		int l, r;
		scanf("%d%d", &l, &r);
		solve(l, r);
	}

    return 0;
}