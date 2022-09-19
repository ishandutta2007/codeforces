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


int main(){
    ios::sync_with_stdio(false);//cin.tie(0);cout.tie(0);
    ll n,p;
    cin >> n;
    str a,b;
    cin >> a >> b;
    ll a00=0,a01=0,a10=0,a11=0;
    for(int i =0;i<n;i++){
        if(a[i] == '0'){
            if(b[i] == '0')a00++;
            if(b[i] == '1')a01++;
        } else {
            if(b[i] == '0')a10++;
            if(b[i] == '1')a11++;
        }
    }
    cout << a00*(a10+a11) + a10*(a01);
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