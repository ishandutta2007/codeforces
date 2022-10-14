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

void solve () {
    int n, k;
    cin >> n >> k;
    int input[n];
    fop (i,0,n) cin >> input[i];
    vector <int> ans(k * 2 + 2, 0);
    fop (i,0,n / 2) {
        if (input[i] > input[n - i - 1]) swap(input[i], input[n - i - 1]);
        ans[0] += 2;
        ans[input[i] + 1]--;
        ans[input[i] + input[n - i - 1]]--;
        ans[input[i] + input[n - i - 1] + 1]++;
        ans[input[n - i - 1] + k + 1]++;
    }
    int anss = 864197532, now = 0;
    fop (i,0,k * 2 + 2) {
        now += ans[i];
        anss = min(anss, now);
    }
    cout << anss << endl;
}

int main () {
    int t;
    cin >> t;
    while (t--) solve();
}