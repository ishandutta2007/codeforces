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
	int n, a[111000], k = 0;
	vector < int > v[111000];
	bool b[111000];
	memset(b, 0, sizeof(b));
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> a[i];
		if(a[i] == i) {
			k++;
			b[i] = 1;
		}
		else v[a[i]].pb(i);
	}
	int m = k;
	for(int i = 0; i<n; i++){
		if(!b[i]){
			if(v[i].size()!=0) m = k+1;
			int ss = v[i].size();
			for(int j = 0; j<ss; j++){
				if(a[i] == v[i][j]){
					cout << k+2;
					return 0;
				}
				b[v[i][j]] = 1;
			}
		}
	}
	cout << max(k, m);
    return 0;
}