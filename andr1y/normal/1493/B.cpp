// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll pc[]={0, 1, 2, 5, 8};
ll gs[]={0, 1, 5, -1, -1, 2, -1, -1, 8, -1};
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll h, m, hn, mn;
        char skip;
        cin >> h >> m >> hn >> skip >> mn;
        while(true){
            ll v1 = hn/10, v2= hn%10, v3 = mn/10, v4=mn%10;
            bool o1=0, o2=0, o3=0, o4=0;
            for(ll i = 0;i<5;i++){
                if(v1==pc[i]) o1=1;
                if(v2==pc[i]) o2=1;
                if(v3==pc[i]) o3=1;
                if(v4==pc[i]) o4=1;
            }
            if(o1&&o2&&o3&&o4){
                ll g1 = gs[v4];
                ll g2 = gs[v3];
                ll g3 = gs[v2];
                ll g4 = gs[v1];
                if(g1*10+g2<h&&g3*10+g4<m){
                    cout<<v1<<v2<<':'<<v3<<v4<<'\n';
                    break;
                }
            }
            mn++;
            if(mn==m)mn=0, hn++;
            if(hn==h)hn=0;
        }
    }
}