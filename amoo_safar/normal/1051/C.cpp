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
const ll MAXN = (ll) 1e2 + 10;
const ll INF = (ll) 9223372036854775;

char out[MAXN];
ll a[MAXN];
ll t[MAXN];
vector<ll> on;
vector<ll> tw;
vector<ll> th;
vector<ll> ot;


void fi(ll t, ll o, char c){
    ll i = 0;
    while(t > 0){
        if(a[i] == o) {
            out[i] = c;
            t--;
        }
        i++;
    }

}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fill(out, out + 102, 'B');
    ll n;
    cin >> n;
    for(int i = 0;i<n;i++) cin >> a[i];
    for(int i = 0;i<n;i++) t[a[i]]++;
    for(int i = 1;i<=100;i++){
        if(t[i] == 1)on.pb(i);
        if(t[i] == 2)tw.pb(i);
        if(t[i] >= 3)ot.pb(i);
    }
    for(auto v : tw) fi(2, v, 'A');
    if(on.size() % 2 == 0){
        for(auto v : ot) fi(t[v],v,'A');
        for(int i = 0;i<on.size()/2;i++) fi(1,on[i],'A');
        for(int i = on.size()/2;i<on.size();i++) fi(1,on[i],'B');
    } else {
        if(ot.size() == 0){
            cout << "NO" << endl;
            return 0;
        }
        on.pb(ot.back());
        ot.pop_back();
        for(auto v : ot) fi(t[v],v,'A');
        for(int i = 0;i<on.size()/2;i++) fi(1,on[i],'B');
        for(int i = on.size()/2;i<on.size();i++) fi(1,on[i],'A');
    }
    cout << "YES" << endl;
    for(int i = 0;i<n;i++)cout << out[i];
    return 0;

}