#include <bits/stdc++.h>

using namespace std;

map<vector<int>, int> mp;
int N;
int arr[305];
long long dp[305][705];
long long fact[305], inv[305];
long long MOD = 1e9+7;

long long add(long long a, long long b){
    return (a+b)%MOD;
}

long long mult(long long a, long long b){
    return (a*b)%MOD;
}

long long qikpow(long long b, long long e){
    if(!e){
        return 1;
    }
    long long ret = qikpow(b, e/2);
    ret = mult(ret, ret);
    if(e&1){
        ret = mult(ret, b);
    }
    return ret;
}

long long divd(long long a, long long b){
    return mult(a, qikpow(b, MOD-2));
}

long long pick(long long n, long long r){
    if(n-r < 0){
        return 0;
    }
    return mult(fact[n], inv[n-r]);
}

long long choose(long long n, long long r){
    return mult(pick(n, r), inv[r]);
}

int main(){
    cin >> N;
    fact[0] = 1, inv[0] = 1;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        int T = arr[i];
        fact[i] = mult(fact[i-1], i);
        inv[i] = divd(1, fact[i]);
        vector<int> v;
        for(int j = 2; j<=sqrt(T); j++){
            if(T%j == 0){
                int xr = 0;
                while(T%j == 0){
                    T /= j;
                    xr ^= j;
                }
                if(xr){
                    v.push_back(xr);
                }
            }
        }
        if(T-1){
            v.push_back(T);
        }
        sort(v.begin(), v.end());
        mp[v]++;
    }
    int idx = 0, tot = 0;
    dp[0][0] = 1;
    for(auto p : mp){
        int n = p.second;
        for(int b = 0; b<=N; b++){
            for(int k = 1; k<=min(n, tot+1); k++){
                for(int x = 0; x<=min(b, k); x++){
                    dp[idx+1][b+n-k-x] = add(dp[idx+1][b+n-k-x],
                            mult(dp[idx][b],
                                 mult(mult(fact[n], choose(n-1, k-1)), mult(choose(b, x), choose(tot-b+1, k-x)))));
                }
            }
        }
        tot += n;
        idx++;
    }
    cout << dp[idx][0] << "\n";
}