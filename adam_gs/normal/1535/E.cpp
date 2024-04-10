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
const int LIM=3e5+7;
ll ile[LIM], nxt[LIM][20], koszt[LIM];
int main() {
        int q;
        cin >> q >> ile[0] >> koszt[0];
        rep(i, q) {
                int x;
                cin >> x;
                if(x==1) {
                        ll p, a, c;
                        cin >> p >> a >> c;
                        ile[i+1]=a;
                        koszt[i+1]=c;
                        nxt[i+1][0]=p;
                        for(int j=1; j<20; ++j) nxt[i+1][j]=nxt[nxt[i+1][j-1]][j-1];
                } else {
                        ll v, w, ans=0, kupione=0;
                        cin >> v >> w;
                        while(w && ile[v]) {
                                int p=v;
                                for(int j=19; j>=0; --j) if(ile[nxt[p][j]]) p=nxt[p][j];
                                int mi=min(ile[p], w);
                                ans+=mi*koszt[p];
                                ile[p]-=mi;
                                w-=mi;
                                kupione+=mi;
                        }
                        cout << kupione << " " << ans << endl;
                }
        }
}