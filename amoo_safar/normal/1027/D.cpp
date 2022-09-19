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
ll const MAXN = (ll)1e6 + 10;

ll se[MAXN];
ll nex[MAXN];
ll c[MAXN];
ll vi[MAXN];

vector<ll> vis;


int main(){
    ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    ll x;
    for(int i =0;i<n;i++)cin >> c[i];
    for(int i =0;i<n;i++){
        cin >> x;
        nex[i] = x-1;
    }
    ll m,po,out = 0;
    for(int i = 0; i < n; i++){
        if(se[i] == 1)continue;
        po = i;
        while(true){
            if(se[po] == 1){
                while(vis.size() > 0){
                    se[vis.back()] = 1;
                    vis.pop_back();
                }
                break;
            }
            if(vi[po] == 1){
                m = c[po];
                se[po] = 1;
                while(vis.back() != po){
                    se[vis.back()] = 1;
                    m = min(m, c[vis.back()]);
                    vis.pop_back();
                }
                out += m;
                while(vis.size() > 0){
                    se[vis.back()] = 1;
                    vis.pop_back();
                }
                break;
            }

            vis.push_back(po);
            vi[po] = 1;
            po = nex[po];
        }
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