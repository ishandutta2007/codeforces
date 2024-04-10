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
	int a[111], n, b[111][111];
	cin >> n;
	memset(b, 0, sizeof(b));
	for(int i = 0; i<n; i++){
		cin >> a[i];
		for(int j = 0; j<a[i]; j++){
			int x;
			cin >> x;
			b[i][x] = 1;
		}
	}
	for(int i  = 0; i<n; i++){
		bool ok = 1;
		for(int j = 0; j<i; j++){
			int cnt = 0;
			for(int k = 1; k<101; k++) {
				if(b[i][k] == b[j][k] && b[i][k] == 1){
					cnt++;
				}
			}
			if(cnt == a[j]) ok = 0;
		}
		for(int j = i+1; j<n; j++){
			int cnt = 0;
			for(int k = 1; k<101; k++) {
				if(b[i][k] == b[j][k] && b[i][k] == 1){
					cnt++;
				}
			}
			if(cnt == a[j]) ok = 0;
		}
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
    return 0;
}