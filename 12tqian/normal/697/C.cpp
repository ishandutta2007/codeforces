#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pll pair<ll, ll>
static map<pll, ll> m;
bool contains(ll x, ll y){
    map<pll, ll>::iterator it = m.find(make_pair(x, y));
    if(it != m.end()){
        return true;
    }
    return false;
}
ll lca(ll a, ll b, ll w){
    ll x = a;
    ll y = b;
    while(x!= y){
        if(x>y){
            if(contains(x, x>>1)){
                m[make_pair(x, x>>1)] += w;
                m[make_pair(x>>1, x)] += w;

            }
            else{
                m[make_pair(x, x>>1)] = w;
                m[make_pair(x>>1, x)] = w;
            }
           //cout << "m: " <<  x << " " << (x>>1) << " " << w  << " " << m[make_pair(x, x>>1)]<< endl;
            x = (x >> 1);
        }
        else{
            if(contains(y, y>>1)){
                m[make_pair(y, y>>1)]  += w;
                m[make_pair(y>>1, y)] += w;
            }
            else{
                m[make_pair(y, y>>1)] = w;
                m[make_pair(y>>1, y)] = w;
            }
            //cout << "m: " <<  y << " " << (y>>1) << " " << w<<  " " << m[make_pair(y, y>>1)] << endl;
            y = (y >> 1);
        }
    }
    return x;
}
ll lca1(ll u, ll v){
    ll x = u;
    ll y = v;
    ll fin = 0;
    while(x!= y){
        if(x>y){
            if(contains(x, x>>1)){
                fin += m[make_pair(x, x>>1)];
                //cout << "good: " <<  x << " " << (x>>1) << " " << m[make_pair(x, y)]<< endl;
            }
            else{
                //cout << "good: " <<  x << " " << (x>>1) << endl;
            }

            x = (x >> 1);
        }
        else{
            if(contains(y>>1, y)){
                fin += m[make_pair(y, y>>1)];
                //cout << "good: " <<  y << " " << (y>>1) << " " << m[make_pair(y>>1, y)]<< endl;
            }
            else{
                //cout << "good: " <<  y << " " << (y>>1) << endl;
            }
            y = (y >> 1);
        }
    }
    return fin;
}
int main(){
    int q;
    scanf("%d", &q);
    for(int i = 0; i<q; i++){
        int d;
        scanf("%d", &d);
        if(d == 1){
            ll v, u;
            ll w;
            cin >> v >> u;
            cin >> w;
            lca(u, v, w);
        }
        else{
            ll v, u;
            cin >> v >> u;
            ll res = lca1(u, v);
            cout <<  res  <<  endl;
        }
    }
    return 0;
}