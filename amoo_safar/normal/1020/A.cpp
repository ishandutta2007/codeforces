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
    ios::sync_with_stdio(false);//cin.tie(0);cout.tie(0);
    ll n,h,a,b,q;
    cin >> n >> h >> a >> b >> q;
    ll x1,y1,x2,y2;
    ll d;
    for(int i = 0;i<q;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2)cout << abs(y1-y2) << endl;
        else{
            d = 0;
            if(y1 > b) {d +=(y1-b);y1=b;}
            if(y1 < a) {d +=(a-y1) ;y1 = a;}
            cout << d + abs(x1-x2) + abs(y1-y2)<< endl;
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