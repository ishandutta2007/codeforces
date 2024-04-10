// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    string c="blue";
    bool cc=1;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        if(s=="lock") cc=0;
        else if(s=="unlock") cc=1;
        else if(cc) c=s;
    }
    cout<<c;
}