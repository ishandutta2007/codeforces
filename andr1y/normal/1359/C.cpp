//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll N = 2e5+228;

signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll h, c, t;
        cin >> h >> c >> t;
        h<<=1;
        c<<=1;
        t<<=1;
        ll mid = (h+c)>>1;
        if(t<=mid) cout << "2\n";
        else {
            ll l = 1, r = 1e7;
            while (r - l > 2) {
                ll m1 = l + (r-l)/3;
                ll m2 = r - (r-l)/3;
                ld vk1 = (((ld) 1) * ((h + c) * m1 + h)) / (m1 + m1 + 1);
                ld vk2 = (((ld) 1) * ((h + c) * m2 + h)) / (m2 + m2 + 1);
                ld tk = t;
                ld v1 = abs(tk-vk1);
                ld v2 = abs(tk-vk2);
                if(v1<=v2) r=m2;
                if(v2<=v1) l=m1;
            }
            ld mv=1e9, mp=-1;
            for(ll i = max(0ll, l-100);i<=l+100;i++){
                ld vk1 = (((ld) 1) * ((h + c) * i + h)) / (i + i + 1);
                ld tk = t;
                ld v1 = abs(tk-vk1);
                if(v1<mv){
                    mv=v1;
                    mp=i;
                }
            }
            cout<<mp+mp+1<<'\n';
        }
    }
}