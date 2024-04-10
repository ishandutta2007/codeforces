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
ll const MAXN = (ll)1e5 + 10;

ll b[310][310];
ll a[310];
ll f[310];

int main(){
    ios::sync_with_stdio(false);//cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> b[i][j];
    }
    for(int i = 0; i < n; i++) cin >> a[i];
    ll mi;
    for(int i = 0;i < n; i++){
        fill(f, f + n + 1, 0);
        mi = 500ll;
        for(int j = 0; j < n; j++){
            if(a[j] == i + 1)continue;
            if(mi > a[j]){
                 mi = a[j];
                 f[mi] = 1;
            }
        }
        for(int j = 0; j < n;j++){
            if(f[b[i][j]] == 1){
                cout << b[i][j] << " ";
                break;
            }
        }
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