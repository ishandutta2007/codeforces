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
const ll INF = (ll) 3e18;
const ld EPS = (ld) 1e-8;


ll a[MAXN];
vector<ll> ze;
vector<ll> po;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;

    ll g = 0;
    for(int i =0;i<n;i++){
        cin >> a[i];
        if(a[i] < 0){
            g++;
        }
    }
    ll m = -1;
    if(g%2==1){
        for(int i =0;i<n;i++){
            if(a[i] < 0){
                if(m == -1) m = i ;
                else {
                    if(abs(a[i]) < abs(a[m]) ) m =i;
                }
            }
        }
        ze.pb(m+1);
        for(int i = 0;i<n;i++){
            if(i == m)continue;
            if(a[i] == 0)ze.push_back(i+1);
            else po.push_back(i+1);
        }
    }else{
        for(int i = 0;i<n;i++){
            if(a[i] == 0)ze.push_back(i+1);
            else po.push_back(i+1);
        }
    }
    while(ze.size() > 1){
        cout << 1 << " " << ze.back();
        ze.pop_back();
        cout << " " << ze.back() << endl;
    }
    if((po.size()>=1) and (ze.size()>=1)) cout << "2 " << ze.back() << endl;
    while(po.size() > 1){
        cout << 1 << " " << po.back();
        po.pop_back();
        cout << " " << po.back() << endl;
    }
    return 0;
}

/*
*/