#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld Pi = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 9223372036854775;

ll ps[MAXN];


vector<ll> ve;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll T,d,l,u, oc;
    cin >> T;
    while(T--){
        str s;
        cin >> s;
        d = 0;
        l = 0;
        u = 0;
        for(int i = 0;i<s.size();i++){
            if((s[i]>='0') and (s[i]<='9') and (d==1))oc = i;
            if((s[i]>='0') and (s[i]<='9'))d=1;
            if((s[i]>='A') and (s[i]<='Z') and (u==1))oc = i;
            if((s[i]>='A') and (s[i]<='Z'))u=1;
            if((s[i]>='a') and (s[i]<='z') and (l==1))oc = i;
            if((s[i]>='a') and (s[i]<='z'))l=1;
        }
        //debug(d);
        //debug(l);
        //debug(u);
        if(d+u+l == 3){
            cout << s << endl;
            continue;
        }

        if(d+u+l == 2){
            if(d == 0) s[oc] = '0';
            if(u == 0) s[oc] = 'A';
            if(l == 0) s[oc] = 'a';
        }else{
            if(d == 1){
                s[0] = 'a';
                s[1] = 'A';
            }
            if(u == 1){
                s[0] = 'a';
                s[1] = '0';
            }
            if(l == 1){
                s[0] = '0';
                s[1] = 'A';
            }
        }
        cout << s << endl;
    }

    return 0;

}