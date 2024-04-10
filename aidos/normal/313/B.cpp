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
	string s;
	cin >> s;
	int n = s.size(), a[n + 100], m;
	a[0] = 0;
	a[1] = 0;
	for(int i = 2; i<=n; i++){
		a[i] = a[i-1];
		if(s[i-1] == s[i-2]) a[i]++;
	}
	cin >> m;
	for(int i = 0; i<m; i++){
		int x, y;
		cin >> x >> y;
		cout << a[y] - a[x] << endl;
	}
    return 0;
}