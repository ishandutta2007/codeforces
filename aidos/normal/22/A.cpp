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
#define all(v) (v).begin(), (v).end()
#define forit(it, v) for(__typeof(v.begin()) it = v.begin(); it!=v.end(); it++)
#define rep(i, n) for(int i = 0; i<n; i++)
#define REP(i, k, n, z) for(int i = k; i<=n; i+=z)
#define vi vector<int>
#define vvi vector<vector<int> >
using namespace std;
ll n, a[111];
int main () {
	cin >> n;
	rep(i, n) cin >> a[i];
	sort(a, a+n);
	int j=1;
	while(j<n && a[j] == a[0]) j++;
	if(j == n) cout << "NO";
	else cout << a[j];
    return 0;
}