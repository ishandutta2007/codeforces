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
        int x, l, r, s;
        cin >> x >> l >> r >> s;
        int n=r-l+1;
        int aktsum=0, T[n];
        rep(i, n) {
                T[i]=i+1;
                aktsum+=T[i];
        }
        aktsum=s-aktsum;
        if(aktsum<0) {
                cout << "-1\n";
                return;
        }
        for(int i=n-1; i>=0; --i) {
                int p=min(T[i]+aktsum, x-(n-1-i));
                aktsum-=p-T[i];
                T[i]=p;
        }
        if(aktsum!=0) {
                cout << "-1\n";
                return;
        }
        int odw[x+1];
        rep(i, x) odw[i+1]=0;
        rep(i, n) odw[T[i]]=1;
        int akt=1;
        rep(i, l-1) {
                while(odw[akt]) ++akt;
                cout << akt << " ";
                ++akt;
        }
        rep(i, n) cout << T[i] << " ";
        rep(i, x-r) {
                while(odw[akt]) ++akt;
                cout << akt << " ";
                ++akt;
        }
        cout << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        cin >> _;
        while(_--) solve();
}