//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 15;
string a[N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, m;
        cin >> n >> m;
        for(ll i  =0;i<n;i++) cin>> a[i];
        string s = a[0];
        bool o2=1;
        for(ll ch = 0;ch<m&&o2;ch++){
            for(ll to = 0;to<n&&o2;to++){
                char org = s[ch];
                s[ch]=a[to][ch];
                bool ok =1;
                for(ll t1=1;t1<n&&ok;t1++){
                    ll neq=0;
                    for(ll t2=0;t2<m&&neq<2;t2++) if(a[t1][t2]!=s[t2])neq++;
                    if(neq>1)ok=0;
                }
                if(ok){
                    o2=0;
                    cout << s << '\n';
                }
                s[ch]=org;
            }
        }
        if(o2)cout<<"-1\n";
    }
}