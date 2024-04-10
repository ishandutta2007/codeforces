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

const ll MOD = 998244353ll;
ll const MAXN = (ll)1e5 + 10;

ll h, po = 0;

pll a[2 * MAXN];

void seg(ll l, ll r, ll le){
    if(l > r) return ;
    l <<= (h-le);
    for(int i = le; i < h; i++){
        r <<= 1;
        r++;
    }
    a[po] = mp(l, r);
    po ++;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll q;
    cin >> h >> q;
    ll aa, b, c, d;
    for(int i = 0; i < q; i++){
        cin >> aa >> b >> c >> d;
        if(d == 0) seg(b, c, aa);
        else {
            seg(1ll << (aa-1), b - 1, aa);
            seg(c + 1, (1ll << aa) - 1, aa);
        }
    }

    a[po] = mp(1ll << h, 1ll << h);
    po++;
    sort(a, a + po);
    //for(int i =0;i<po;i++)cerr << a[i].F << " " << a[i].S << endl;
    ll la = -1;
    ll v = (1ll << (h-1)) - 1;
    //cerr << v;
    for(int i = 0; i < po; i++){
        if(a[i].F > v + 1){
            if(a[i].F - v == 2){
                if(la == -1){
                    la = v + 1;
                } else {
                    cout << "Data not sufficient!";
                    return 0;
                }
            } else {
                cout << "Data not sufficient!";
                return 0;
            }
        }
        v = max(v, a[i].S);
    }
    if(la == -1) cout << "Game cheated!";
    else cout << la;
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