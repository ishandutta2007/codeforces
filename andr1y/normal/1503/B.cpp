// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll cnt[4];
vector<pll> pos1, pos2;
signed main(){
    ll n;
    cin >> n;
    ll mx2 = ((n&1) ? (n+1)*(n/2) : (n*n)/2);
    for(ll D = 1;D<n+n-1;D+=2){
        for(ll i = 0;i<n;i++){
            ll j = D-i;
            if(j<0||j>=n) continue;
            pos2.push_back({i+1, j+1});
        }
    }
    for(ll D = 0;D<n+n-1;D+=2){
        for(ll i = 0;i<n;i++){
            ll j = D-i;
            if(j<0||j>=n) continue;
            pos1.push_back({i+1, j+1});
        }
    }
    ll mx1 = n*n-mx2;
    ll tk3 = -1;
    for(ll a, i = 0;i<n*n;i++){
        cin >> a;
        if(a==1){
            if(cnt[2]<mx2){
                cout<<2<<' '<<pos2[cnt[2]].x<<' '<<pos2[cnt[2]].y<<endl;
                cnt[2]++;
            }else{
                tk3=1;
                cout<<3<<' '<<pos1[cnt[1]].x<<' '<<pos1[cnt[1]].y<<endl;
                cnt[1]++;
            }
        }else if(a==2){
            if(cnt[1]<mx1){
                cout<<1<<' '<<pos1[cnt[1]].x<<' '<<pos1[cnt[1]].y<<endl;
                cnt[1]++;
            }else{
                tk3=2;
                cout<<3<<' '<<pos2[cnt[2]].x<<' '<<pos2[cnt[2]].y<<endl;
                cnt[2]++;
            }
        }else if(a==3){
            if(cnt[2]<mx2){
                cout<<2<<' '<<pos2[cnt[2]].x<<' '<<pos2[cnt[2]].y<<endl;
                cnt[2]++;
            }else{
                cout<<1<<' '<<pos1[cnt[1]].x<<' '<<pos1[cnt[1]].y<<endl;
                cnt[1]++;
            }
        }
    }
}