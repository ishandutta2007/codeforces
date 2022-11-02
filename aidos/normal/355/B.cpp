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
	int c1, c2, c3, c4, n, m, a[1100], b[1100], sum = 0, x = 0;
	cin >> c1 >> c2 >>c3 >> c4;
	cin >> n >> m;
	for(int i = 0; i<n; i++){
		cin >> a[i];
		sum += min(a[i]*c1, c2);
	}
	for(int i = 0; i<m; i++){
		cin >> b[i];
		x += min(b[i]*c1, c2);
	}
	cout << min(min(c4, min(x+min(sum, c3), sum + min(x, c3))), 2*c3);
    return 0;
}