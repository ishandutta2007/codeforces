// keep calm and eat pizza.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll a[N], cnt[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll q;
	cin >> q;
	while(q--){
        for(ll i = 0;i<111;i++) cnt[i]=0;
        ll n, sa=0;
        cin >> n;
        if(n==1){
            cin >> a[0];
            cout<<"T\n";
            continue;
        }
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            cnt[a[i]]++;
            sa+=a[i];
        }
        ll mx=100, ban=111;
        bool ok = 0;
        for(;true;){
            while(mx>=0&&cnt[mx]==0) --mx;
            if(mx<=0) break;
            ll m2=mx;
            if(cnt[m2]==1&&ban==m2){
                --m2;
                while(m2>=0&&cnt[m2]==0)--m2;
                if(m2<=0) break;
            }
            cnt[m2]--;
            cnt[m2-1]++;
            ban=m2-1;
            ok^=1;
        }
        if(ok) cout<<"T\n";
        else cout<<"HL\n";
	}
}