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
const ll MAXN = (ll) 1e5 + 10;
const ll INF = (ll) 9223372036854775807;

bool CMP(pll a, pll b){
    return a.S < b.S;
}

pll a[MAXN];
pll b[MAXN];

ll dist(pll a, pll b){
    return (ll)(pow((a.F - b.F), 2)) + (ll)(pow((a.S - b.S), 2));
}

map<pll, ll> co;


ll to_check = 10;

pair< pll, pll > solve(ll l, ll r){

    /* returning if */
    ll ans = INF;
    if(r - l <= 3){
        ll ansi = 0, ansj = 1;
        for(int i = l; i < r; i++){
            for(int j = l; j < r; j++){
                if( i == j ) continue;
                if(ans > dist(a[i], a[j])){
                    ansi = i;
                    ansj = j;
                    ans = dist(a[i], a[j]);
                }
            }
        }
        return mp(a[ansi], a[ansj]);
    }
    /////////////////////////////////




    /* divide and choose better one */
    ll mid = (l + r) / 2;
    pair< pll, pll > ansl = solve(l, mid), ansr = solve(mid, r);

    pll first = ansl.F;
    pll second = ansl.S;

    if(dist(ansr.F, ansr.S) < dist(first, second)){
        first = ansr.F;
        second = ansr.S;
    }

    ans = dist(first, second);
    //////////////////////////////////

    /* finding left  and right of middle (mid - ans) && (mid + ans) */
    ll lef = l;
    ll rig = r;
    for(int i = l; i < r; i++){
        if(a[i].F < a[mid].F - ans)lef = i;
    }

    for(int i = r - 1; i >= l; i--){
        if(a[i].F > a[mid].F + ans)rig = i;
    }

    sort(a + lef, a + mid, CMP);
    sort(a + mid, a + rig, CMP);
    //////////////////////////////////



    /* two pointer && and try to find min */
    ll sec_pointer = mid;

    for(int i = lef; i < mid; i++){
        if(sec_pointer < rig){
            while(a[i].S > a[sec_pointer].S){
                sec_pointer ++;
                if(sec_pointer == rig) break;
            }
        }
        for(int j = max(mid, sec_pointer - to_check); j < min(rig, sec_pointer + to_check); j++){
            if(dist(a[i], a[j]) < ans){
                ans = dist(a[i], a[j]);
                first = a[i];
                second = a[j];
            }
        }
    }

    sort(a + lef, a + rig);
    /////////////////////////




    return mp(first, second);
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    ll v,s = 0;
    for(int i = 1; i <= n; i++){
        cin >> v;
        s += v;
        a[i - 1] = mp(i, s);
    }
    for(int i = 0; i < n; i++) co[a[i]] = i;
    //for(int i = 0; i < n; i++) b[i] = a[i];
    sort(a, a + n);

    pair< pll, pll > ans = solve(0, n);

    ll fi = co[ans.F];
    ll se = co[ans.S];

    cout << (ll)(pow((ans.F.F - ans.S.F), 2)) + (ll)(pow((ans.S.S - ans.F.S), 2));
    //cout << min(fi, se) << " " << max(fi, se) << " ";
    //cout << fixed << setprecision(6) << dist(ans.F, ans.S);
    return 0;
}



/*
9
1 1
-5 3
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