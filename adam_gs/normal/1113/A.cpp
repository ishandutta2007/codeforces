#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int n, v;
        cin >> n >> v;
        int w=min(v,n-1);
        rep(i, n-v-1) w+=i+2;
        cout << w;
}