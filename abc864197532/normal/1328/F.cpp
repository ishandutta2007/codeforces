#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define X first
#define Y second

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <lli> input(n), pre(n + 1);
    fop (i,0,n) cin >> input[i];
    sort(input.begin(), input.end());
    pre[0] = 0;
    fop (i,0,n) pre[i+1] = pre[i] + input[i];
    lli ans = LLONG_MAX;
    for (int i = 0, j = 0; i < n; i = j) {
    	while (j < n and input[j] == input[i]) j++;
    	if (j - i >= k) ans = 0;
        lli ans1 = pre[n] - pre[i] - 1ll * input[i] * (n - i), ans2 = 1ll * input[i] * i - pre[i];
        if (n - i >= k) ans = min(ans, ans1 - (n - i - k));
        if (j >= k) ans = min(ans, ans2 - (j - k));
        ans = min(ans, ans1 + ans2 - (n - k));
	}
	cout << max(ans, 0ll) << endl;
}