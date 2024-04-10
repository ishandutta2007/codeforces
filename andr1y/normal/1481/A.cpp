// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll x, y;
        cin >> x >> y;
        string s;
        cin >> s;
        ll ls=0, rs=0, us=0, ds=0;
        for(auto i : s){
            if(i=='R') rs++;
            if(i=='L') ls++;
            if(i=='U') us++;
            if(i=='D') ds++;
        }
        bool ox = (x<=0?ls>=-x:rs>=x);
        bool oy = (y<=0?ds>=-y:us>=y);
        if(ox&&oy) cout<<"yes\n";
        else cout<<"no\n";
    }
}