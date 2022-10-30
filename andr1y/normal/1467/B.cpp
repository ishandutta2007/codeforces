// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 3e5+228;
ll a[N];
char code[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            code[i]=0;
        }
        ll k=0;
        for(ll i = 1;i+1<n;i++){
            if(a[i]>a[i-1]&&a[i]>a[i+1]) code[i]=1;
            if(a[i]<a[i-1]&&a[i]<a[i+1]) code[i]=2;
            if(code[i]) k++;
        }
        ll del=(k?1:0);
        for(ll i =2;i<n;i++){
            if(code[i]==code[i-2]&&a[i]==a[i-2]&&code[i]) {
                del=2;
                break;
            }
        }
        for(ll i =2;i<n;i++){
            if(code[i]==2&&code[i-1]==1&&(i==2||a[i-2]<=a[i-3]||a[i-2]<=a[i])) del=2;
            if(code[i]==1&&code[i-1]==2&&(i==2||a[i-2]>=a[i-3]||a[i-2]>=a[i])) del=2;
        }
        for(ll i =1;i+1<n;i++){
            if(code[i]==2&&code[i-1]==1&&(i==n-2||a[i+1]>=a[i+2]||a[i+1]>=a[i-1])) del=2;
            if(code[i]==1&&code[i-1]==2&&(i==n-2||a[i+1]<=a[i+2]||a[i+1]<=a[i-1])) del=2;
        }
        for(ll i = 1;i+1<n;i++){
            if(code[i]!=code[i-1]&&code[i-1]==code[i+1]&&code[i]&&code[i-1]) del=3;
        }
        cout<<k-del<<'\n';
    }

}