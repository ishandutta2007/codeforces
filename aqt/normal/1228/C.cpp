#include <bits/stdc++.h>

using namespace std;

long long X, N;
long long MOD = 1e9+7;
vector<int> p;
map<int, long long> mp;

long long qikpow(long long b, long long e){
    if(e == 0){
        return 1;
    }
    long long mid  = qikpow(b, e/2);
    mid = mid*mid%MOD;
    if(e&1){
        mid *= b;
        mid %= MOD;
    }
    return mid;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> X >> N;
    for(int k = 2; k<=sqrt(X); k++){
        if(X%k == 0){
            p.push_back(k);
            while(X%k == 0){
                X /= k;
            }
        }
    }
    if(X > 1){
        p.push_back(X);
    }
    for(long long k : p){
        long long prod = k;
        while(true){
            mp[k] += N/prod;
            mp[k] %= (int) 1e9+6;
            if(N/k < prod){
                break;
            }
            prod *= k;
        }
    }
    long long ans = 1;
    for(auto k : mp){
        ans *= qikpow(k.first, k.second);
        ans %= MOD;
    }
    cout << ans << endl;
}