#include <bits/stdc++.h>

using namespace std;

long long A, B;
long long ans = LLONG_MAX;

void solve(long long t, long long a){
    vector<pair<long long, long long>> v;
    for(long long l = 1; l<=sqrt(a); l++){
        if(a%l == 0){
            v.push_back({l, a/l});
        }
    }
    for(long long n = 1; n<=sqrt(t); n++){
        if(t%n == 0){
            for(auto p : v){
                if(p.first <= n && p.second <= t/n){
                    ans = min(ans, 2*(n+t/n));
                }
            }
        }
    }
}

int main(){
    cin >> A >> B;
    solve(A+B, A);
    solve(A+B, B);
    cout << ans << endl;
}