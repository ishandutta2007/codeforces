#include <bits/stdc++.h>

using namespace std;

int T;

int main(){
    cin >> T;
    while(T--){
        long long n, k;
        cin >> n >> k;
        long long tot = 0;
        while(n){
            tot += n%k;
            n -= n%k;
            n/=k;
            tot++;
        }
        cout << tot-1 << endl;
    }
}