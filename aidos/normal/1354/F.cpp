#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)80;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;

int n, k;
int dp[maxn][maxn];
int u[maxn][maxn];
pii a[maxn];
vector<pii> b;
int get(int pos, int K) {
    if(K < 0) return -inf;
    if(pos==b.size()) {
        if(K > 0) return -inf;
        return 0;
    }
    int &res = dp[pos][K];
    if(u[pos][K]) return res;
    u[pos][K] = 1;
    res = max(get(pos+1, K - 1) + (k-1-K) * b[pos].first + a[b[pos].second].first, get(pos+1, K) + (k - 1) * b[pos].first);
    return res;
}
int calc(int pos) {
    b.clear();
    for(int i = 0; i < n; i++) {
        if(i != pos) {
            b.push_back(make_pair(a[i].second, i));
        }
    }
    sort(b.begin(), b.end());
    memset(u, 0, sizeof u);
    return get(0, k-1);
}
vector<int> A, B;
void rec(int pos, int K) {
    if(pos==b.size())
        return;
    if(get(pos, K) == get(pos+1, K - 1) + (k-K-1) * b[pos].first + a[b[pos].second].first){
        A.push_back(b[pos].second);
        rec(pos+1, K-1);
        return;
    }
    rec(pos+1, K);
    B.push_back(b[pos].second);
}
void out(int pos) {
    calc(pos);
    A.clear();
    B.clear();
    rec(0, k-1);
    cout << A.size() + 2 * B.size() + 1 << "\n";
    for(int i = 0; i < A.size(); i++) {
        cout << A[i] + 1 << " ";
    }
    for(int i = 0; i < B.size(); i++) {
        cout << B[i] + 1 << " ";
        cout<<-B[i] - 1 << " ";
    }
    cout << pos + 1 << "\n";
}
void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    int opt = -1;
    int ans = -inf;
    for(int i = 0; i < n; i++) {
        int val = calc(i) + a[i].first + a[i].second  * (k-1);
        if(val > ans) {
            ans = val;
            opt = i;
        }
        //cout << val << "\n";
    }
    //return;
   // cout << ans << "\n";
    out(opt);

}

int main() {
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}