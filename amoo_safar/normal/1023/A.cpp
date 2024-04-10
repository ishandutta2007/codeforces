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

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,m;
    cin >> n >> m;
    str s,t;
    cin >> s >> t;
    ll ind = -1;
    for(int i = 0;i<n;i++){
        if(s[i] == '*')ind = i;
    }
    if(ind == -1){
        if(s == t)cout << "YES" << endl;
        else cout<< "NO";
    } else {
        if(n > m + 1){
            cout << "NO";
            return 0;
        }
        ll f = 1;
        for(int i =0 ; i< ind ;i++){
            if(s[i]!= t[i]) f = 0;
        }
        for(int i =0 ; i< n - ind - 1 ;i++){
            if(s[ind + i + 1]!= t[m - (n-ind - 1 - i)]) f = 0;
        }
        if(f == 0)cout << "NO";
        else cout << "YES";

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