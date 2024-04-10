#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
void solve() {
        int n;
        cin >> n;
        set<int>st;
        int lst;
        cin >> lst;
        st.insert(lst);
        auto akt=st.lower_bound(lst);
        int T[n];
        rep(i, n-1) cin >> T[i+1];
        for(int i=1; i<n; ++i) {
                st.insert(T[i]);
                if(T[i]>lst) {
                        ++akt;
                        if(*akt!=T[i]) {
                                cout << "NO\n";
                                return;
                        }
                } else if(T[i]<lst) {
                        --akt;
                        if(*akt!=T[i]) {
                                cout << "NO\n";
                                return;
                        }
                }
                lst=T[i];
        }
        cout << "YES\n";
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        cin >> _;
        while(_--) solve();
}