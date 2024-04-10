#include <bits/stdc++.h>

using namespace std;

long long a, b;

long long solve(long long k){
    long long t = (k-(a%k))%k;
    long long res = (a+t)*(b+t)/__gcd((a+t), b+t);
    return res;
}

int main(){
    cin >> a >> b;
    long long d = abs(a-b);
    long long k = 0, ans = LLONG_MAX;
    for(long long i = 1; i <= sqrt(d); i++){
        if(d%i == 0){
            long long res = solve(i);
            if(res < ans){
                ans = res;
                k = (i-(a%i))%i;
            }
            else if(res == ans && i < k){
                ans = res;
                k = min(k, (i-(a%i))%i);
            }
            i = d/i;
            res = solve(i);
            if(res < ans){
                ans = res;
                k = (i-(a%i))%i;
            }
            else if(res == ans){
                ans = res;
                k = min(k, (i-(a%i))%i);
            }
            i = d/i;
        }
    }
    cout << k << endl;
}