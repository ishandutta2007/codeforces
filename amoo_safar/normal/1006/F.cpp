#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll const MAXN = 21;

ll a[MAXN][MAXN];

map<ll,ll> be;
map<ll,ll> af;

ll xorr ;
ll n,m;

void tob(ll x, ll y, ll xo){
    //cout << x << " fff " << y << "    " << xo << endl;
    xorr = xo^a[x][y];
    if((x == 0) and (y == 0)){
        be[xorr] = be[xorr] + 1;
        return ;
    }
    ll xo1 = xorr;
    ll xo2 = xorr;
    if(x > 0)tob(x-1,y,xo1);
    if(y > 0)tob(x,y-1,xo2);
}

void toc(ll x, ll y, ll xo, ll endd){
    if((x == n-endd-1) and (y == endd)){
        af[xo] = af[xo] + 1;
        return ;
    }
    xorr = xo^a[x][y];
    ll xo1 = xorr;
    ll xo2 = xorr;
    if(x > n-endd-1)toc(x-1,y,xo1,endd);
    if(y > endd)toc(x,y-1,xo2,endd);
}


int main(){
    ll k;
    cin >> n >> m >> k;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++) cin >> a[i][j];
    }
    //cout << endl;
    ll t = 0;
    ll fir,sec;
    for(int i = 0;i<min(n,m);i++){
        be.clear();
        af.clear();
        tob(n-1-i,i,0);
        toc(n-1,m-1,0,i);
        //cout << " aaa "<< i << endl;
        //cout << endl;
        //cout << be.size() << endl;
        for(map<ll,ll>::iterator it = be.begin(); it != be.end(); ++it) {
            //cout << it->first <<  "\n";
            fir = it->first;
            sec = it -> second;
            t = t+(sec*af[k^fir]);
            //cout << t  << endl;
            //cout << be[i];
        }
    }
    cout << t;
    return 0;
}