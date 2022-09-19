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




int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, s = 0;
    cin >> n;
    ll v;
    for(int i =0;i<n;i++){
        cin >> v;
        s += v;
        s--;
        if(s%2==0) cout << 2 << endl;
        else cout << 1 << endl;
    }

    return 0;
}



/*
7
2 3 1 5 2 19 1
3
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