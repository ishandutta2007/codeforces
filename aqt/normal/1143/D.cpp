#include <bits/stdc++.h>

using namespace std;

long long N, K, A, B;
long long mini = LLONG_MAX, maxi = LLONG_MIN;

void solve(long long X, long long Y){
    for(long long i = 1; i<=N; i++){
        long long D = (i*K)+Y - X;
        long long G = __gcd(D, N*K);
        long long R = N*K/G;
        mini = min(mini, R);
        maxi = max(maxi, R);
    }
}

int main(){
    cin >> N >> K >> A >> B;
    solve(A, B);
    solve(K-A, K-B);
    solve(K-A, B);
    solve(A, K-B);
    cout << mini << " " << maxi << endl;
}