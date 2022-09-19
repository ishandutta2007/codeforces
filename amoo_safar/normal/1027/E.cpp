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

const ll MOD = 998244353ll;
ll const MAXN = (ll)1e6 + 10;

ll dp2[503][503];
ll aa[503];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,kk;
    cin >> n >> kk;
    kk--;
    ll l = 0,s,out = 0,ss;
    for(int i = 1;i <= min(n,kk);i++){
        dp2[1][1] = 1;
        for(int j = 2; j <= n; j++){
            ss = 0;
            for(int k = 2;k<=min(i,n);k++){
                ss += dp2[j-1][k-1];
                ss %= MOD;
                dp2[j][k] = dp2[j-1][k-1];
            }
            dp2[j][1] = ss + dp2[j-1][min(i,n)];
        }
        s = 0;
        for(int j = 1; j <= min(n,i);j++){

            s += dp2[n][j];
            s %= MOD;
        }
        //cerr << i << " " << s << endl;
        s -= l;
        s%=MOD;
        if(s < 0) s += MOD;

        for(int i = 0; i < 503; i++){
            fill(dp2[i],dp2[i]+503,0);
        }
        /*
        dp2[1][1] = s;
        for(int j = 2; j <= n; j++){
            for(int k = 1;k<=min(kk/i,n);k++){
                if(k == 1){
                    for(int f = 1;f<503;f++){
                        dp2[j][k] += dp2[j-1][f];
                        dp2[j][k] %= MOD;
                    }
                } else dp2[j][k] = dp2[j-1][k-1];

            }

        }


        for(int j = 1; j <= min(n,kk/i);j++){
            out += dp2[n][j];
            out %= MOD;
        }
        for(int i = 0; i < 503; i++){
            fill(dp2[i], dp2[i]+503, 0ll);
        }*/
        l += s;
        l%= MOD;
        aa[i] = s;
        //cerr << s <<" "<< l << endl;;
        //cerr << s << endl;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1; j <= min(n,kk/i);j++){
            out += (aa[i]*aa[j])*2;
            out %= MOD;
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