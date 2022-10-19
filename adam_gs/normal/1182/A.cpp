#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int pot(int a, int b) {
        int ans=1;
        while(b>0) {
                if(b%2==1) ans*=a;
                a*=a;
                b/=2;
        }
        return ans;
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int n;
        cin >> n;
        if(n%2==1) cout << 0; else {
                cout << pot(2, n/2);
        }
}