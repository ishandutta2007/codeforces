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

pair<pll,ll> a[MAXN];
ll out[MAXN];

int main(){
    ios::sync_with_stdio(false);//cin.tie(0);cout.tie(0);
    cout.precision(16);
    ll n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i].F.F;
    for(int i = 0; i < n; i++) cin >> a[i].F.S;
    for(int i = 0; i < n; i++) a[i].S = i;
    sort(a, a + n);
    reverse(a, a + n);
    //for(int i = 0; i < n; i++) cerr << a[i].F.F << " " << a[i].F.S << " " << a[i].S << endl;
    if(n % 2 == 1){
        out[a[0].S] = 1;
        for(int i = 1; i < n; i+=2){
            if(a[i].F.S > a[i+1].F.S){
                out[a[i].S] = 1;
            } else {
                out[a[i+1].S] = 1;
            }
        }
    } else {
        out[a[0].S] = 1;
        out[a[1].S] = 1;
        for(int i = 2; i < n; i+=2){
            if(a[i].F.S > a[i+1].F.S){
                out[a[i].S] = 1;
            } else {
                out[a[i+1].S] = 1;
            }
        }
    }
    cout << 1 + n / 2 << endl;
    for(int i = 0;i<n;i++){
        if(out[i] == 1)cout << i + 1 << " ";
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