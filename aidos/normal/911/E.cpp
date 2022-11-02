#pragma optimize("", on)
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int) 998244353;
const int inf = (1<<30) - 1;
int n, m;
int a[maxn];
int u[maxn];
void solve() {
    cin >> n >> m;
    vector<int> ans, st;
    vector<int> d;
    st.emplace_back(n + 1);
    for(int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        ans.emplace_back(x);
        u[x] = 1;
        if(st.back() < x) {
            cout << -1 << "\n";
            return;
        }
        st.emplace_back(x);
        while(st.size() > 1 && st.back() == d.size() + 1) {
            d.emplace_back(st.back());
            st.pop_back();
        }
    }
    while(d.size() < n) {
        while(st.back() > d.size() + 1) {
            int x = st.back();
            st.push_back(x-1);
            ans.emplace_back(x-1);
        }
        while(st.size() > 1 && st.back() == d.size() + 1) {
            d.emplace_back(st.back());
            st.pop_back();
        }
    }
    for(int to: ans)cout<<to<<" ";
}


int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}