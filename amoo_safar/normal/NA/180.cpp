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
    ll n,m;
    str s;
    cin >> n >> m;
    ll fr=INF,fc=INF,lr=-1,lc=-1;
    for(int i = 0;i<n;i++){
        cin >> s;
        for(int j =0;j<m;j++){
            if(s[j] == 'B'){
                fc = min(j + 1ll,fc);
                fr = min(i + 1ll,fr);
                lr = max(i + 1ll,lr);
                lc = max(j + 1ll,lc);
            }
        }
    }
    cout << (fr+lr)/2 << " " << (fc+lc)/2;
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