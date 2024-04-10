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

pll a[4 * MAXN];
pll b[MAXN];

ld dist(pll a, pll b){
    return sqrt( pow((a.F - b.F), 2) + pow((a.S - b.S), 2) );
}

map<pll, pll> co;
map<pll, ll> co2;


ll to_check = 13;

pair< pll, pll > solve(ll l, ll r){

    /* returning if */
    ld ans = 100000000.00;
    if(r - l <= 5){
        ll ansi = 0, ansj = 1;
        for(int i = l; i < r; i++){
            for(int j = l; j < r; j++){
                if( i == j ) continue;
                if((abs(a[i].F) == abs(a[j].F)) and (abs(a[i].S) == abs(a[j].S))) continue;
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
            if((abs(a[i].F) == abs(a[j].F)) and (abs(a[i].S) == abs(a[j].S))) continue;
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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> b[i].F >> b[i].S;
        a[4 * i] = mp(b[i].F, b[i].S);
        a[4 * i + 1] = mp((-1) * b[i].F, b[i].S);
        a[4 * i + 2] = mp(b[i].F, (-1) * b[i].S);
        a[4 * i + 3] = mp((-1) * b[i].F, (-1) * b[i].S);
        /*for(int j = 4 * i; j < 4 * i + 4; j++){
            cerr << j << " " << a[j].F << " " << a[j].S << endl;
        }*/
        if(co2[a[4 * i]] == 0){
            co[a[4 * i]] = mp(i + 1, 1);
            co2[a[4 * i]] ++;
        } else {
            if(co[a[4 * i]].F == i + 1) continue;
            cout << co[a[4 * i]].F << " " << co[a[4 * i]].S << " " << i + 1 << " " << 4;
            return 0;
        }

        if(co2[a[4 * i + 1]] == 0){
            co[a[4 * i + 1]] = mp(i + 1, 2);
            co2[a[4 * i + 1]] ++;
        } else {
            if(co[a[4 * i + 1]].F == i + 1) continue;
            cout << co[a[4 * i + 1]].F << " " << co[a[4 * i + 1]].S << " " << i + 1 << " " << 3;
            return 0;
        }

        if(co2[a[4 * i + 2]] == 0){
            co[a[4 * i + 2]] = mp(i + 1, 3);
            co2[a[4 * i + 2]] ++;
        } else {
            if(co[a[4 * i + 2]].F == i + 1) continue;
            cout << co[a[4 * i + 2]].F << " " << co[a[4 * i + 2]].S << " " << i + 1 << " " << 2;
            return 0;
        }

        if(co2[a[4 * i + 3]] == 0){
            co[a[4 * i + 3]] = mp(i + 1, 4);
            co2[a[4 * i + 3]] ++;
        } else {
            if(co[a[4 * i + 3]].F == i + 1) continue;
            cout << co[a[4 * i + 3]].F << " " << co[a[4 * i + 3]].S << " " << i + 1 << " " << 1;
            return 0;
        }

    }

    /*for(map<pll, pll>::const_iterator it = co.begin(); it != co.end(); it++){
        cerr << (it -> F).F << " " << (it -> F).S << " " << (it -> S).F << " " << (it -> S).S << endl;
    }*/

    sort(a, a + 4 * n);

    pair< pll, pll > ans = solve(0, 4 * n);

    pll fi = co[ans.F];
    pll se = co[ans.S];


    cout << fi.F << " " << fi.S << " " << se.F << " " << 5 - se.S;
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