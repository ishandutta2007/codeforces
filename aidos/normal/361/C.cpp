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
	ll n, m, a[11111], b[11111], ux = 1000ll*1000ll*1000ll, arr=1000ll*1000ll*1000ll*1000ll*1000ll, t[11111], l[11111], r[11111], d[11111];
	for(int i = 0; i<11100; i++){
		a[i] = arr;
		b[i] = 0;
	}
		
	cin >> n >> m;
	for(int i = 0; i<m; i++){
		cin >> t[i] >> l[i] >> r[i] >> d[i];
		if(t[i] == 1){
			for(int j = l[i]; j<=r[i]; j++)
				b[j] += d[i];
		}
		else {
			for(int j = l[i]; j<=r[i]; j++){
				if(d[i]-b[j]<a[j]){
					a[j] = d[i]-b[j];
				}
			}
		}
	}
	for(int i = 1; i<=n; i++){
		if(a[i] == arr) a[i] = 0;
		b[i] = a[i];
	}
	for(int i = 1; i<=n; i++){
		if(labs(a[i]) > ux){
			cout << "NO";
			return 0;
		}
	}
	bool ok=1;
	for(int i = 0; i<m; i++){
		if(t[i] == 1){
			for(int j = l[i]; j<=r[i]; j++)
				a[j] += d[i];
		}
		else {
			ll mx = a[l[i]];
			for(int j = l[i]+1; j<=r[i]; j++)
				if(mx < a[j]) mx = a[j];
			if(mx != d[i]){
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES\n";
	for(int i = 1; i<=n; i++)
		cout << b[i] << " ";
    return 0;
}