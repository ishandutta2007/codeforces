#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0 ; a < (b); ++a)

int main() {
    int n, s;
    cin >> n;
    int t[n];
    rep(i, n) cin >> t[i];
    if(t[0]%2==t[1]%2) {
        s=(t[1]+1)%2;
    } else if(t[1]%2==t[2]%2) s=t[0]%2; else s=t[1]%2;
    rep(i, n) if(t[i]%2==s) cout << i+1;
}