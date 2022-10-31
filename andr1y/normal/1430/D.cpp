// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll a[N], ac=0, fs=0;
string s;
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ac=0, fs=0;
        ll n;
        cin >> n >> s;
        ll bs=0, bc=s[0]-'0';
        for(ll i = 0;i<n;i++){
            if(s[i]-'0'==bc){
                bs++;
            }else{
                a[ac++]=bs;
                bs=1, bc^=1;
            }
        }
        a[ac++]=bs;
        ll res=0;
        for(ll i = 0;i<ac;i++){
            ++res;
            if(a[i]>1){
                continue;
            }else{
                fs=max(fs, i+1);
                while(fs<ac&&a[fs]==1) fs++;
                if(fs==ac){
                    ++i;
                }else{
                    a[fs]--;
                }
            }
        }
        cout<<res<<'\n';
    }
}