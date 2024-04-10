#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ll inf = 0x3fff3fff3fff3fff;
const ll N = 5e5+20;
ll p[N];
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        n+=n;
        string s;
        cin >> s;
        p[0]=0;
        for(int i = 1;i<=n;i++){
            p[i]=p[i-1]+(s[i-1]=='('?1:-1);
        }

        ++n;
        ll fz = 1;
        while(fz<n && p[fz]>=0) fz++;
        if(fz==n){
            cout<<"0\n";
            continue;
        }
        ll lz = n-2;
        while(p[lz]>=0) --lz;
        ll mx1=0, mx2=0, mx3=0;
        ll mp1=0, mp2=fz, mp3=n-1;
        for(int i=0;i<fz;i++) if(p[i]>mx1) mx1=p[i], mp1=i;
        for(int i=fz;i<=lz;i++) if(p[i]>mx2) mx2=p[i], mp2=i;
        for(int i=lz+1;i<n;i++) if(p[i]>mx3) mx3=p[i], mp3=i;
        if(mx1+mx3>=mx2){
            cout<<"1\n"<<mp1+1<<' '<<mp3<<'\n';
        }else{
            cout<<"2\n"<<1<<' '<<mp2<<'\n'<<mp2+1<<' '<<n-1<<'\n';
        }
    }   
}