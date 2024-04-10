#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int t;
        cin >> t;
        while(t--) {
                int a, b;
                cin >> a >> b;
                if(a%2==1 && b%2==1) {
                        cout << (a-1)/2*b+b/2+1;
                } else {
                        if(b%2==0) swap(a, b);
                        cout << b*a/2;
                }
                cout << '\n';
        }
}