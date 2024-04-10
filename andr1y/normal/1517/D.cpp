// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 505;
const ll inf = 0x3fff3fff3fff3fff;
ll goh[N][N];
ll gov[N][N];
//vector<pll> d[N];
pll len[2][N][N];
ll LCFI=0, LCFE=0;
struct cgrea{
    bool operator()(pair<ll, pll> &a, pair<ll, pll> &b){
        return a.x>b.x;
    }
};
inline bool dist(ll a, ll b, ll c, ll d){
    return abs(a-c)+abs(b-d)<=10;
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, m, k;
    cin >> n >> m >> k;
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j+1<m;j++){
            cin >> goh[i][j];
        }
    }
    for(ll i=0;i+1<n;i++){
        for(ll j = 0;j<m;j++) cin >> gov[i][j];
    }
    if(k&1){
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<m;j++) cout<<"-1 ";
            cout<<'\n';
        }
        return 0;
    }
    k/=2;
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<m;j++){
            ll fi=0, fe=1;
            LCFE++;
            len[fe][i][j]={LCFE, 0};
            for(ll IT=0;IT<k;IT++){
                LCFI++;
                for(ll ki=i-IT;ki<=i+IT;ki++){
                    if(ki<0||ki>=n) continue;
                    ll dki = abs(ki-i);
                    for(ll kj=j-(IT-dki);kj<=j+(IT-dki);kj++){
                        if(kj<0||kj>=m||len[fe][ki][kj].x<LCFE) continue;

                        if(ki+1<n){
                            if(len[fi][ki+1][kj].x<LCFI) len[fi][ki+1][kj]={LCFI, inf};
                            len[fi][ki+1][kj].y=min(len[fi][ki+1][kj].y, len[fe][ki][kj].y+gov[ki][kj]);
                        }

                        if(kj+1<m){
                            if(len[fi][ki][kj+1].x<LCFI) len[fi][ki][kj+1]={LCFI, inf};
                            len[fi][ki][kj+1].y=min(len[fi][ki][kj+1].y, len[fe][ki][kj].y+goh[ki][kj]);
                        }

                        if(ki-1>=0){
                            if(len[fi][ki-1][kj].x<LCFI) len[fi][ki-1][kj]={LCFI, inf};
                            len[fi][ki-1][kj].y=min(len[fi][ki-1][kj].y, len[fe][ki][kj].y+gov[ki-1][kj]);
                        }

                        if(kj-1>=0){
                            if(len[fi][ki][kj-1].x<LCFI) len[fi][ki][kj-1]={LCFI, inf};
                            len[fi][ki][kj-1].y=min(len[fi][ki][kj-1].y, len[fe][ki][kj].y+goh[ki][kj-1]);
                        }
                    }
                }
                swap(fi, fe);
                swap(LCFI, LCFE);
            }
            ll mr=inf;
            for(ll ki=i-k;ki<=i+k;ki++){
                if(ki<0||ki>=n) continue;
                ll dki = abs(ki-i);
                for(ll kj=j-(k-dki);kj<=j+(k-dki);kj++){
                    if(kj<0||kj>=m||len[fe][ki][kj].x<LCFE) continue;
                    mr=min(mr, len[fe][ki][kj].y);
                }
            }
            cout<<mr+mr<<' ';
        }
        cout<<'\n';
    }
}