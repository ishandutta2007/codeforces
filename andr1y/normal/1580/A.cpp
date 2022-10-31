//ulala
//code by 255
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ll inf = 0x3fff3fff3fff3fff;
const ll N = 405;
ll a[N][N];
ll val1[N], val2[N], pval[N];
ll sj[N][N];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll qq;cin>>qq;while(qq--){
        ll n, m;
        cin >> n >> m;
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<m;j++){
                char e;
                cin >> e;
                if(e=='1') a[i][j] = 1;
                else a[i][j]=0;
                sj[j][i] = a[i][j];
                if(i) sj[j][i] += sj[j][i-1];
            }
        }
        ll res=inf;
        for(ll i1=0;i1<n;i1++){
            for(ll i2 = i1+4;i2<n;i2++){
                for(ll j = 0;j<m;j++){
                    val1[j] = (a[i1][j]^1) + (a[i2][j]^1) + (sj[j][i2-1] - sj[j][i1]);
                    val2[j] = (i2-i1-1)-(sj[j][i2-1]-sj[j][i1]);
                }
                ll sp = val1[0];
                for(ll j = 0;j+1<m;j++){
                    pval[j] = val2[j] - sp;
                    if(j) pval[j]=min(pval[j], pval[j-1]);
                    sp+=val1[j+1];
                }
                sp=val1[0]+val1[1]+val1[2];
                for(ll j = 3;j<m;j++){
                    res=min(res, val2[j]+sp+pval[j-3]);
                    sp+=val1[j];
                }
            }
        }
        cout<<res<<'\n';
    }
}