// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+1488;

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        string a, b;
        cin >> n >> a >> b;
        vector<ll> r;
        ll fd = 0, td = n-1, in=0;
        for(ll i = n-1;i>=0;i--){
            char f = (in?(a[fd]=='1'?'0':'1'):a[fd]), t = b[i];
            if(f!=t){
                r.push_back(i+1);
                if(fd>td) fd--;
                else fd++;
                swap(fd, td);
                in^=1;
            }else{
                r.push_back(1);
                a[fd]=(a[fd]=='1'?'0':'1');
                r.push_back(i+1);
                if(fd>td) fd--;
                else fd++;
                swap(fd, td);
                in^=1;
            }
        }
        cout << r.size()<<' ';
        for(auto i : r) cout<<i<<' ';
        cout<<'\n';
    }
}