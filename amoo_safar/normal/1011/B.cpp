#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const long MOD = (long)1e9 + 7;
ll const MAXN = 100001;


ll a[100];
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    ll n,m;
    cin >> n >> m;
    ll b;
    for(int i =0;i<m;i++){
        cin >> b;
        a[b-1] ++;
    }
    ll t = 0;
    for(int i = 100;i> 0;i--){
        t = 0;
        for(int j = 0;j<100;j++) t = t + (a[j]/i);
        //cout << i << t << endl;
        if(t >= n){
            cout << i << endl;
            return 0;
        }
    }
    cout << 0;
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