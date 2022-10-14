#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
const int mod = 1e9 + 7, x = 864197532, N = 5087, logN = 18, K = 500, C = 1 << 20;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, w;
    cin >> n >> w;
    vector <lli> ans(w, 0);
    fop (i,0,n) {
        int sz;
        cin >> sz;
        vector <int> v(sz);
        fop (i,0,sz) cin >> v[i];
        /*
        123
         123
          123
           123
            123
        0123
         0123
          0123
        */
        deque <int> dq;
        int back = 0;
        fop (i,0,sz) {
            while (dq.size() && dq.front() <= i - (w - sz + 1)) dq.pop_front();
            while (dq.size() && v[dq.back()] <= v[i]) dq.pop_back();
            dq.pb(i);
            int ne;
            if (i < w - sz) ne = max(0, v[dq.front()]);
            else ne = v[dq.front()];
            ans[i] += ne - back;
            back = ne;
        }
        int now = max(0, sz - (w - sz + 1));
        while (1) {
            while (dq.size() && dq.front() <= now) dq.pop_front();
            if (dq.empty()) break;
            int ne = max(0, v[dq.front()]);
            ans[w - sz + now + 1] += ne - back;
            back = ne;
            now++;
        }
    }
    fop (i,1,w) ans[i] += ans[i - 1];
    printv(ans);
}