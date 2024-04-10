// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1==x2){
        ll d = abs(y1-y2);
        cout<<x1+d<<' '<<y1<<' '<<x1+d<<' '<<y2<<'\n';
    }else if(y1==y2){
        ll d = abs(x1-x2);
        cout<<x1<<' '<<y1+d<<' '<<x2<<' '<<y2+d<<'\n';
    }else{
        ll d = abs(x1-x2);
        if(x1>x2){
            swap(x1, x2);
            swap(y1, y2);
        }
        if(d!=abs(y1-y2)) cout<<"-1\n";
        else{
            cout<<x2<<' '<<y1<<' '<<x1<<' '<<y2<<'\n';
        }
    }
}