#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld Pi = 3.14159265359;

const long MOD = (long)1e9 + 7;
ll const MAXN = (ll)5e4 + 10;

pll a[MAXN];

bool CMP(pll a, pll b){
    return a.F * a.S * (100 - b.S) > b.F * b.S * (100 - a.S);
}

int main(){
    ios::sync_with_stdio(false);//cin.tie(0);cout.tie(0);
    cout.precision(16);
    ld out = 0.0;
    ll n;
    cin >> n;
    for(int i = 0; i < n; i ++)cin >> a[i].F >> a[i].S;
    sort(a, a + n, CMP);
    //for(int i = 0; i < n; i++)cerr << a[i].F << " " << a[i].S << endl;
    ll s = 0;
    for(int i = 0; i < n; i++) s += (100-a[i].S);
    ld c, d;
    for(int i = 0; i < n; i++){
        s -= (100-a[i].S);
        c = 1.0 + (s/1.0/100.0);
        out = out + a[i].F * ((c * a[i].S + (100 - a[i].S)) / 1.0 / 100.0);
    }
    cout << fixed << out;

    return 0;
}



/*
           _____           ______              ______        _______________           _______________
          /     \         |      \            /      |      /               \         /               \
         /       \        |       \          /       |     /                 \       /                 \
        /   ___   \       |   |\   \        /   /|   |    /    ___________    \     /    ___________    \
       /   /   \   \      |   | \   \      /   / |   |   |    /           \    |   |    /           \    |
      /   /_____\   \     |   |  \   \    /   /  |   |   |   |            |    |   |   |            |    |
     /               \    |   |   \   \  /   /   |   |   |    \___________/    |   |    \___________/    |
    /    _________    \   |   |    \   \/   /    |   |    \                   /     \                   /
   /    /         \    \  |   |     \      /     |   |     \                 /       \                 /
  /____/           \____\ |___|      \____/      |___|      \_______________/         \_______________/

*/