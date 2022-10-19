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
const int LIM=1e6+7;
int tr[4*LIM], nr[LIM], jaki[4*LIM];
char T[LIM];
void solve() {
        int k;
        cin >> k;
        int n=1<<k, l=0;
        rep(i, n) tr[n+i]=1;
        for(int poziom=1; poziom<=k; ++poziom) {
                rep(i, 1<<k-poziom) {
                        cin >> T[l];
                        nr[l]=(1<<(k-poziom))+i;
                        jaki[nr[l]]=l;
                        if(T[l]=='?') {
                                tr[nr[l]]=tr[2*nr[l]]+tr[2*nr[l]+1];
                        } else if(T[l]=='0') {
                                tr[nr[l]]=tr[2*nr[l]];
                        } else tr[nr[l]]=tr[2*nr[l]+1];
                        ++l;
                }
        }
        int q;
        cin >> q;
        rep(i, q) {
                int a;
                cin >> a; --a;
                cin >> T[a];
                a=nr[a];
                while(a) {
                        if(T[jaki[a]]=='?') {
                                tr[a]=tr[2*a]+tr[2*a+1];
                        } else if(T[jaki[a]]=='0') {
                                tr[a]=tr[2*a];
                        } else tr[a]=tr[2*a+1];
                        a/=2;
                }
                cout << tr[1] << '\n';
        }
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        while(_--) solve();
}