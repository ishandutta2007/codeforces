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
        pair<int,int> T[4];
        rep(i, 4) {
                cin >> T[i].st;
                T[i].nd=i;
        }
        sort(T, T+4);
        if(min(T[3].nd, T[2].nd)==0 && max(T[3].nd, T[2].nd)==1) {
                cout << "NO\n";
        } else if(min(T[3].nd, T[2].nd)==2 && max(T[3].nd, T[2].nd)==3) {
                cout << "NO\n";
        } else cout << "YES\n";
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        cin >> _;
        while(_--) solve();
}