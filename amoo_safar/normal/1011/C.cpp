#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const long MOD = (long)1e9 + 7;
ll const MAXN = 100001;


ll a[1000];
ll b[1000];
ll c[2000];
int main(){
    //ios::sync_with_stdio(false);
	//cin.tie(0); cout.tie(0);
    ll n;
    ld m;
    cin >> n >> m;
    //cout << 2;
    ld w = m;
    //cout << m;
    ld out = 0.0;
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    for(int i =0;i<n;i++){
        cin >> b[i];
    }
    for(int i =0;i<n;i++){
        c[i*2] = a[i];
    }
    for(int i =1;i<n;i++){
        c[i*2-1] = b[i];
    }
    c[2*n-1] = b[0];

    ld fu;

    for(int i = 2*n-1;i>=0;i--){
        if(c[i] == 1){
            cout << -1;
            return 0;
        }
        fu = w/((c[i]-1)/1.0);
        out += fu;
        w += fu;
    }
    cout.precision(12);
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