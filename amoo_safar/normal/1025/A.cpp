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
ll const MAXN = (ll)1e6 + 10;

ll a[26];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    str s;
    cin >> s;
    if(n == 1){
        cout << "YES";
        return 0;
    }
    for(int i = 0;i<n;i++){
        a[s[i]-'a']++;
        if(a[s[i]-'a'] == 2){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
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