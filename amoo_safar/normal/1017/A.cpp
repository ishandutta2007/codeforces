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

ll a[1000];
int main(){
    ios::sync_with_stdio(false);//cin.tie(0);cout.tie(0);
    ll n,p;
    cin >> n;
    ll a1,a2,a3,a4;
    cin >> a1 >> a2 >> a3 >> a4;
    ll s = a1+a2+a3+a4;
    ll t= 1;
    for(int i =1;i<n;i++){
        cin >> a1 >> a2 >> a3 >> a4;
        if(a1+a2+a3+a4 > s)t++;
    }
    cout << t;
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