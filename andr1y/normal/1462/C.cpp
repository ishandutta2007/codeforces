// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
void get(ll n, ll s){
    string num="";
    ll sum=0;
    for(ll i = 1;i<=n;i++){
        num+='0'+i;
        sum+=i;
    }
    for(;sum<s;){
        bool o=0;
        for(ll i = n-1;i>=0&&!o;i--){
            if(num[i]-'0'==10-n+i) continue;
            num[i]++;
            sum++;
            o=1;
            for(ll j = i+1;j<n;j++){
                sum-=num[j]-'0';
                num[j]=num[j-1]+1;
                sum+=num[j]-'0';            }
        }
        if(!o){
            cout<<"-1\n";
            return;
        }
    }
    cout<<num<<'\n';
    return;
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll s;
        cin >> s;
        if(s>45){
            cout<<"-1\n";
            continue;
        }
        ll fk = 9, fs=1;
        while(s>fk) fk+=9-fs, fs++;
        get(fs, s);
    }
}