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
const int LIM=2e3+7;
int odp[LIM], n, ile[2];
vector<pair<int,int>>ans;
void pyt(int r) {
        cout << "? " << r << endl;
        rep(i, n) cin >> odp[i];
}
void solve() {
        cin >> n;
        pyt(1);
        rep(i, n) ++ile[odp[i]%2];
        vector<int>kand;
        if(ile[0]<=ile[1]) {
                rep(i, n) if(odp[i]%2==0) kand.pb(i+1);
        } else {
                rep(i, n) if(odp[i]%2==1) kand.pb(i+1);
        }
        for(auto i : kand) {
                if(i!=1) pyt(i);
                rep(j, n) if(odp[j]==1) {
                        ans.pb({i, j+1});
                }
        }
        cout << "!" << endl;
        for(auto i : ans) {
                cout << i.st << " " << i.nd << endl;
        }
}
int main() {
        int _=1;
        while(_--) solve();
}