#include <bits/stdc++.h>

using namespace std;

int N, K;
int typ[2000005], lst[2000005];
long long power[2000005];
long long MOD = 1e9+7;
vector<int> fact[2000005];
long long cnt[2000005];

long long add(long long a, long long b){
    return (a+b)%MOD;
}

long long sub(long long a, long long b){
    return (a-b+MOD)%MOD;
}

long long mult(long long a, long long b){
    return a*b%MOD;
}

long long qikpow(long long b, long long e){
    if(!e){
        return 1;
    }
    long long res = qikpow(b, e>>1);
    res = mult(res, res);
    if(e&1){
        res = mult(b, res);
    }
    return res;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    typ[1] = 1;
    for(int i = 2; i<=K; i++){
        if(typ[i] == 0){
            for(int j = i; j<=K; j+=i){
                if(typ[j] != -1){
                    typ[j]++;
                }
            }
            for(long long j = 1LL*i*i; j<=K; j += 1LL*i*i){
                typ[j] = -1;
            }
        }
    }
    for(int i = 1; i<=K; i++){
        if(typ[i] == -1){
            typ[i] = 0;
            continue;
        }
        else if(typ[i]%2 == 1){
            typ[i] = -1;
        }
        else{
            typ[i] = 1;
        }
        for(int j = i; j<=K; j+=i){
            fact[j].push_back(i);
        }
    }
    typ[1] =1;
    for(int i = 1; i<=K; i++){
        power[i] = qikpow(i, N);
    }
    long long ans = 0;
    long long crnt = 0;
    for(int i = 1; i<=K; i++){
        for(int f : fact[i]){
            if(typ[f] == 1){
                crnt = sub(crnt, power[cnt[f]]);
                cnt[f]++;
                crnt = add(crnt, power[cnt[f]]);
            }
            else{
                crnt = add(crnt, power[cnt[f]]);
                cnt[f]++;
                crnt = sub(crnt, power[cnt[f]]);
            }
        }
        ans = add(ans, crnt^i);
    }
    cout << ans << endl;
}