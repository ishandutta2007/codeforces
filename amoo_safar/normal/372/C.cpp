#include<iostream>
#include<deque>
using namespace std;
typedef long long ll;

ll dp[2][150000];

int main(){
    ll n,m,d,dt,a,b,t,di,lt,sb,sd;
    sb = 0;
    sd = 0;
    deque<ll> de;
    cin >> n >> m >> d;
    for(int k = 0;k < m;k++){
        //cout << 2 << endl;
        cin >> a >> b >> t;
        sb += b;
        if(k == 0){
            lt = t;
            for(int i = 0;i < n;i++)
                dp[0][i] = abs(a-(i+1));
        } else {
            dt = (t-lt)*d*2+1;
            di = min(n-1,(t-lt)*d);
            //deque<ll> de;
            //cout << 2 << endl;
            for(int j = 0; j < di;j++){
                if(de.size() == 0) {
                    de.push_front(j);
                    continue;
                }
                while(dp[0][j] <= dp[0][de.front()]){
                    de.pop_front();
                    if(de.size() == 0){
                        break;
                    }
                }
                de.push_front(j);
            }
            for(int j = 0;j < n;j++){
                dt = abs(a-(j+1));
                if(de.size() == 0) {
                    de.push_front(j);
                    dp[1][j] = dp[0][de.back()]+dt;
                    continue;
                }

                if(j-de.back() > di) de.pop_back();

                if(de.size() == 0){
                    de.push_front(j);
                    dp[1][j] = dp[0][de.back()]+dt;
                    continue;
                }

                if (j+di >= n){
                    dp[1][j] = dp[0][de.back()]+dt;
                    continue;
                }
                while(dp[0][j+di] <= dp[0][de.front()]){
                    de.pop_front();
                    if(de.size() == 0){
                        break;
                    }
                }
                de.push_front(j+di);
                dp[1][j] = dp[0][de.back()]+dt;
            }
            for(int j = 0;j < n;j++){
                dp[0][j] = dp[1][j];
            }
            lt =t;
            de.clear();
        }
    }
    ll ma = dp[0][0];
    for(int j = 0;j < n;j++){
        if(ma > dp[0][j]) ma = dp[0][j];
    }
    //cout << ma << endl;
    cout << sb - ma;
    return 0;
}