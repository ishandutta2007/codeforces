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
        ll k;
        cin >> k;
        ll a=0, s=0;
        while(a<k) {
                ++s;
                a+=2*s-1;
        }
        a-=2*s-1;
        k-=a;
        if(k<=s) {
                cout << k << " " << s << '\n';
        } else {
                k-=s;
                cout << s << " " << s-k << '\n';
        }
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        cin >> _;
        while(_--) solve();
}