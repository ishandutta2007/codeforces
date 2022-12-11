#include <bits/stdc++.h>

using namespace std;

int T;
long long lim[61];
int mob[61];

int main(){
    cin >> T;
    lim[1] = 1e18;
    lim[2] = 1e9;
    lim[3] = 1e6;
    for(int i = 4; i<=60; i++){
        lim[i] = pow(9e18, 1/(i*1.0));
    }
    for(int i = 2; i<=60; i++){
        if(!mob[i]){
            for(int j = i; j<=60; j+=i){
                if(mob[j] != -1){
                    mob[j]++;
                }
            }
            for(int j= i*i; j<=60; j+=i*i){
                mob[j] = -1;
            }
        }
    }
    while(T--){
        long long n;
        cin >> n;
        long long tot = 0;
        for(int i = 1; i<=60; i++){
            if(mob[i] != -1){
                long long l = 1, r = lim[i], t = 1;
                while(l <= r){
                    long long mid = l+r>>1;
                    long long res = 1;
                    for(int k = 1; k<=i; k++){
                        res *= mid;
                    }
                    if(res <= n){
                        l = mid + 1;
                        t = mid;
                    }
                    else{
                        r = mid - 1;
                    }
                }
                if(mob[i]%2){
                    tot -= t - 1;
                }
                else{
                    tot += t - 1;
                }
            }
        }
        cout << tot << endl;
    }
}