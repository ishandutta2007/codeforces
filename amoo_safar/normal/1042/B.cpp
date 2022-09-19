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
const ll MAXN = (ll) 1e3 + 10;
const ll INF = (ll) 9223372036854775;


ll a[MAXN];
map<str , ll> ma;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,k;
    cin >> n;
    str s;
    ma["A"] = INF;
    ma["B"] = INF;
    ma["C"] = INF;
    ma["AB"] = INF;
    ma["AC"] = INF;
    ma["BC"] = INF;
    ma["ABC"] = INF;

    ll a=0,b=0,c=0;
    for(int i = 0;i<n;i++){
        cin >> k >> s;
        sort(s.begin(),s.end());
        //debug(ma[s]);
        ma[s] = min(ma[s], k);
        for(int i = 0;i<s.size();i++){
            if(s[i] == 'A')a=1;
            if(s[i] == 'B')b=1;
            if(s[i] == 'C')c=1;
        }
    }
    if(a+b+c < 3){
        cout << -1;
        return 0;
    }
    cout << min(ma["A"]+ma["B"]+ma["C"],min(ma["ABC"],min(ma["A"]+ma["BC"],min(ma["C"]+ma["AB"],min(ma["B"]+ma["AC"],min(ma["AB"]+ma["BC"],min(ma["AC"]+ma["AB"],ma["AC"]+ma["BC"])))))));
    return 0;

}