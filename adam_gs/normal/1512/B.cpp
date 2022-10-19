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
        vector<pair<int,int>>V;
        char T[n][n];
        rep(i, n) rep(j, n) {
                cin >> T[i][j];
                if(T[i][j]=='*') V.pb({i, j});
        }
        if(V[0].st==V[1].st) {
                T[(V[0].st+1)%n][V[0].nd]='*';
                T[(V[1].st+1)%n][V[1].nd]='*';
        } else if(V[0].nd==V[1].nd) {
                T[V[0].st][(V[0].nd+1)%n]='*';
                T[V[1].st][(V[1].nd+1)%n]='*';
        } else {
                T[V[0].st][V[1].nd]='*';
                T[V[1].st][V[0].nd]='*';
        }
        rep(i, n) {
                rep(j, n) cout << T[i][j];
                cout << '\n';
        }
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        cin >> _;
        while(_--) solve();
}