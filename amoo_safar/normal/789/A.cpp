#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll const MAXN = 21;


int main(){
    ll n,k,a,t = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a;
        t = t +(a + (k - 1)) / k;
    }
    cout << (t + 1) / 2;
    return 0;
}