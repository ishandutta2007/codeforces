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
        int n, mi=101, l=0;
        cin >> n;
        rep(i, n) {
                int a;
                cin >> a;
                if(a<mi) {
                        mi=a;
                        l=0;
                }
                if(a==mi) ++l;
        }
        cout << n-l << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _;
        cin >> _;
        while(_--) solve();
}