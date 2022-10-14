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
vector <int> input;

int solve(int l, int r, int k) {
    vector <int> now, all;
    int ans = 0;
    fop (i,0,input.size()) {
        if (l <= i and i < r) now.pb(input[i]), ans += input[i];
        else all.pb(input[i]);
    }
    sort(all.rbegin(), all.rend());
    sort(now.begin(), now.end());
    int id = 0;
    while (id < now.size() and id < all.size() and now[id] < all[id] and id < k) {
        ans += (all[id] - now[id]);
        id++;
    }
    return ans;
}

int main () {
    int n, k;
    cin >> n >> k;
    input.resize(n);
    fop (i,0,n) cin >> input[i];
    int ans = -864197532;
    fop (i,0,n) {
        fop (j,i+1,n+1) {
            ans = max(ans, solve(i, j, k));
        }
    }
    cout << ans << endl;
}