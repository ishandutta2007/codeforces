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
ll n, m, ans1 = 0, ans2 = 0;
int main () {
	cin >> n >> m;
	REP(i, 2, m, 2) ans1 += (m-i+1);
	REP(i, 2, n, 2) ans2 += (n-i+1);
	cout << ans1 * ans2;
    return 0;
}