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
ll const MAXN = (ll)2e6 + 10;

int main(){
    ios::sync_with_stdio(0);
    ll t;
    cin >> t;
    ll n,f;
    str s;
    ll a,b;
    for(int i =0;i<t;i++){
        cin >> n;
        cin >> s;
        f = 1;
        for(int i = 0; i<n;i++){
            a = s[i];
            b = s[n - 1 - i];
            if(abs(a-b) == 0 or abs(a-b) == 2) continue;
            f = 0;
        }
        if(f == 0)cout << "NO" << endl;
        else cout << "YES" << endl;
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