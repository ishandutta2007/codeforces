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
#define pll pair <long long,long long>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define MAXN 1000000
#define INF 1000000000
using namespace std;
int main () {
    int n, k, l, r;
    cin >> n >>k >> l >> r;
    int ans = __gcd(n, k), ans1, ans2;
    ans = n/ans*k;
    ans1 = (l-1)/ans;
    ans2 = r/ans;
    cout << ans2 -ans1;
	return 0;
}