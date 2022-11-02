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
ll sum[2000100], a[2000100], n;
int main () {
	cin >> n;
	for(int i = 0; i<n; i++)
		scanf("%d", &a[i]);
	sort(a, a+n);
	reverse(a, a+n);
	sum[0] = 0;
	for(int i  =1; i<=n; i++)
		sum[i] = sum[i-1] + a[i-1];
	ll ans = 0;
	for(int i = 1; i<=n; i*=4)
		ans += sum[i];
	cout << ans;
    return 0;
}