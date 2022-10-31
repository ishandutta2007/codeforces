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
        ll x1, y1, x2, y2;
        cin >> x1>>y1>>x2>>y2;
        if(x1==x2&&y1==y2){
            cout<<0;
        }else if(x1==x2||y1==y2){
            cout<<abs(x1-x2)+abs(y1-y2);
        }else{
            cout<<abs(x1-x2)+abs(y1-y2)+2;
        }
        cout<<'\n';
    }
}