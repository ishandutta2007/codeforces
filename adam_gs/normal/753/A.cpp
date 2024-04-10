#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int n;
        cin >> n;
        int p = 0, k = 45;
        while(p < k) {
                int sr=(p+k+1)/2;
                if(sr*(sr+1)/2>n) k=sr-1; else p=sr;
        }
        cout << p << '\n';
        rep(i, p-1) { cout << i+1 << " "; n-=i+1; }
        cout << n;
}