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
typedef pair<pll, pll> ppll;

const ld Pi = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 132674 + 10;
const ll INF = (ll) 9223372036854775807;

ppll a[MAXN];
ppll l[MAXN];
ppll r[MAXN];

bool CMP(ppll a, ppll b){
    return a.F.F < b.F.F;
}


ppll comm(ppll a, ppll b){

    if((a.S.F < b.F.F) or (a.S.S < b.F.S)) return mp(mp(INF, INF), mp(INF+1, INF-1));

    return mp(mp(max(a.F.F, b.F.F), max(a.F.S, b.F.S)), mp(min(a.S.F, b.S.F), min(a.S.S, b.S.S)));

}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,m;
    cin >> n;
    for(int i =0;i<n;i++){
        cin >> a[i].F.F >> a[i].F.S >> a[i].S.F >> a[i].S.S;
    }

    sort(a, a + n, CMP);
    //debug(a[0].F.F);

    ppll ans;

    l[0] = mp(mp(-INF, -INF), mp(INF,INF));
    for(int i = 1;i < n;i++) l[i] = comm(l[i-1], a[i-1]);
    r[n - 1] = mp(mp(-INF, -INF), mp(INF,INF));
    for(int i = n - 2;i >= 0;i--) r[i] = comm(r[i + 1], a[i + 1]);
    for(int i =0;i<n;i ++){
        ans = comm(l[i], r[i]);
        if((ans.F.F > ans.S.F) or (ans.F.S > ans.S.S)) continue;
        //cout << i << endl;
        cout << ans.F.F << " " << ans.F.S;
        return 0;
    }

    return 0;
}



/*
9
1 1
-5 35
0 0 10 8
1 2 6 7
2 3 5 6
3 4 4 5
8 1 9 2
5
0 0 10 8
1 2 6 7
2 3 5 6
3 4 4 5
8 1 9 2

2 10
9 8
20 1
3 -9
1 50
-7 -7
15 -15
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