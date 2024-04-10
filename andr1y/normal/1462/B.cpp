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
        ll n;
        string s;
        cin >> n >> s;
        if(
           (s[0]=='2'&&s[1]=='0'&&s[2]=='2'&&s[3]=='0') ||
           (s[0]=='2'&&s[1]=='0'&&s[2]=='2'&&s[n-1]=='0') ||
           (s[0]=='2'&&s[1]=='0'&&s[n-2]=='2'&&s[n-1]=='0') ||
           (s[0]=='2'&&s[n-3]=='0'&&s[n-2]=='2'&&s[n-1]=='0') ||
           (s[n-4]=='2'&&s[n-3]=='0'&&s[n-2]=='2'&&s[n-1]=='0')
        ) cout<<"yEs\n";
        else cout<<"nO\n";
    }
}