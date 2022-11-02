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
	int n, m, ans = 0;
	cin >> n >> m;
	for(int i = 0; i*i <= n; i++){
		for(int j = 0; j*j <=m; j++){
			if(i*i + j == n && j*j + i == m) ans++;
		}
	}
	cout << ans;
    return 0;
}