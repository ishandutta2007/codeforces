#include <bits/stdc++.h>

using namespace std;

int main(){
    long long a, b;
    cin >> a >> b;
    vector<long long> fac;
    for(long long i = 1; i <= sqrt(a); i++){
        if(a%i == 0){
            fac.push_back(i);
            if(i*i != a){
                fac.push_back(a/i);
            }
        }
    }
    sort(fac.begin(), fac.end());
    long long ans = 0;
    while(b){
        long long cgcd = __gcd(a, b);
        long long nxt = 0;
        for(long long f : fac){
            if(f != cgcd && f%cgcd == 0){
                nxt = max(nxt, b/f*f);
            }
        }
        ans += (b-nxt)/cgcd;
        b = nxt;
    }
    cout << ans << endl;
}