#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0 ;a < (b); ++a)
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int t;
        cin >> t;
        while(t--) {
                int n, m, a, b;
                cin >> n >> m >> a >> b;
                cout << max(a-1, n-a)+max(b-1, m-b) << '\n';
        }
}