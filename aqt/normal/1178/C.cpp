#include <bits/stdc++.h>

using namespace std;

long long MOD = 998244353;
int N, M;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    long long ans = 4;
    for(int i = 2; i<=N; i++){
        ans *= 2;
        ans %= MOD;
    }
    for(int i = 2; i<=M; i++){
        ans *= 2;
        ans %= MOD;
    }
    cout << ans << endl;
}