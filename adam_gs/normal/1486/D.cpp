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
const int LIM=2e5+7, INF=1e9+7;
int T[LIM], n, k, pref[LIM];
bool spr(int x) {
        int l=-1, mi=0;
        rep(i, n) {
                if(T[i]>=x) pref[i]=1; else pref[i]=-1;
                if(i) pref[i]+=pref[i-1];
                if(i>=k) {
                        ++l;
                        mi=min(mi, pref[l]);
                }
                if(i>=k-1 && pref[i]-mi>0) return true;
        }
        return false;
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        cin >> n >> k;
        rep(i, n) cin >> T[i];
        int po=1, ko=n;
        while(po<ko) {
                int sr=(po+ko+1)/2;
                if(spr(sr)) po=sr; else ko=sr-1;
        }
        cout << po << '\n';
}