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


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll a,b,c;
    cin >> a >> b >> c;
    for(int i = 0; i <= min(a,b);i++){
        if((c == a - i + b - i)){
            if((a == 0) or (b == 0) or (c == 0)) continue;

            cout << i << " " << b - i << " " << a - i;
            return 0;
        }
    }
    cout << "Impossible";
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