#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld Pi = 3.14159265359;

const long MOD = (long)1e9 + 7;
ll const MAXN = 400010;

ll a[26];

int main(){
    ios::sync_with_stdio(false);//cin.tie(0);cout.tie(0);
    //cout.precision(16);
    ll n;
    cin >> n;
    for(int i =0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    ll l =1000000002;
    ll out = 0;
    for(int i =n-1;i>=0;i--){
        l = min(l,a[i]);
        l = max(l,0ll);
        out += l;
        l--;
    }
    cout << out;
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