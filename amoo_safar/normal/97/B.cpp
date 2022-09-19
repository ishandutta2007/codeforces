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
ll const MAXN = (ll)1e4 + 10;

set<pll> co;

pll a[MAXN];

void solve(ll l, ll r){
    if(l + 1 == r)return ;
    ll mid = (l + r) / 2;
    solve(l, mid);
    solve(mid, r);
    //cerr <<  a[mid].F;
    for(int i = l; i < r; i++){
        co.insert(mp(a[mid].F, a[i].S));
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].F >> a[i].S;
        co.insert(a[i]);
    }
    sort(a, a + n);
    solve(0, n);
    cout << co.size() << endl;
    for(set<pll>::const_iterator it = co.begin(); it != co.end(); it++){
        cout << (*it).F  << " "  << (*it).S << endl;
    }

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