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
    ll n,q;
    cin >> n >> q;
    ll x,y;
    ll out;
    for(int i =0;i<q;i++){
        cin >> x >> y;
        x--;
        y--;
        if((x+y)%2 == 0){
            if(n%2 == 0){
                cout << x*(n/2) + y/2 + 1<< endl;
            } else {
                out = (x/2)*n + 1;
                if(x%2 == 0) out += (y/2);
                else out += (y / 2) + ((n+1)/2);
                cout << out << endl;
            }
        } else {
            if(n%2 == 0){
                cout << ((n * n) / 2)+x*(n/2) + y/2 + 1 << endl;
            }else{
                out = (n*n / 2)+(x/2)*n + 2;
                if(x%2 == 0) out += (y/2);
                else out += (y / 2) + (n/2);
                cout << out << endl;
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