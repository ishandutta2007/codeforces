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
ll const MAXN = (ll)2e5 + 10;

pair<ll, pll> a[MAXN];
pair<ll, pll> b[MAXN];

ll out[MAXN];

ll merg(ll l, ll mid, ll r){
    ll i, j;
    i = l;
    j = mid + 1;
    ll po = 0;
    while((i <= mid) and (j <= r)){
        if(a[i].S.F < a[j].S.F){
            out[a[i].S.S] += (j - (mid + 1));
            b[po] = mp(a[i].F, mp(a[i].S.F, a[i].S.S));
            i ++;
            po ++;
        } else {
            b[po] = mp(a[j].F, mp(a[j].S.F, a[j].S.S));
            j ++;
            po ++;
        }
    }
    for(int k = i; k <= mid; k++){
        //cerr << k << endl;
        b[po] = mp(a[k].F, mp(a[k].S.F, a[k].S.S));
        out[a[k].S.S] += (j - (mid + 1));
        po ++;
    }
    for(int k = j; k <= r; k++){
        b[po] = mp(a[k].F, mp(a[k].S.F, a[k].S.S));
        po ++;
    }
    for(int k = l; k <= r; k++){
        a[k] = mp(b[k - l].F, mp(b[k - l].S.F, b[k - l].S.S));
    }
    //cerr << l << " mer " << r << endl;
    return 1ll;
}

ll merge_sort(ll l, ll r){
    //cerr << l << " " << r << endl;
    if(l == r)return 1ll;
    merge_sort(((l + r) / 2) + 1ll, r);
    merge_sort(l, (l + r) / 2);

    merg(l, (l + r) / 2, r);
    return 1ll;
}

int main(){
    ll n;
    cin >> n;
    for(int i = 0;i < n; i++){
        cin >> a[i].F >> a[i].S.F;
        a[i].S.S = i;
    }
    sort(a, a + n);
    /*for(int i = 0;i < n; i++)cerr << a[i].F << " " << a[i].S.F << " " << a[i].S.S << endl;
    cerr << endl;*/
    merge_sort(0, n - 1);
    /*for(int i = 0; i < n; i++)cerr << a[i].F << " " << a[i].S.F << " " << a[i].S.S << endl;*/
    for(int i = 0; i < n; i++)cout << out[i] << endl;
    return 0;
}



/*
8
1 20
4 13
5 16
2 43
15 34
20 20
3 100
14 15
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