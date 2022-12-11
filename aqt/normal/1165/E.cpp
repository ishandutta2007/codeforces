#include <bits/stdc++.h>

using namespace std;

int N;
long long MOD = 998244353;
vector<long long> a, b;

int main(){
    cin >> N;
    for(long long i = 1; i <=N; i++){
        long long n;
        cin >> n;
        a.push_back(n);
        a[i-1] *= (i)*(N-i+1);
    }
    for(long long i = 1; i<=N; i++){
        long long n;
        cin >> n;
        b.push_back(n);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    long long ans = 0;
    for(long long i = 0; i<N; i++){
        ans += a[i]%MOD*b[i];
         ans %= MOD;
    }
    cout << ans << endl;
}