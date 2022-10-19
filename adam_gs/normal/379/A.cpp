#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
        int a, b, ans=0, x=0;
        cin >> a >> b;
        while(a>0) {
                ans+=a;
                x+=a;
                a=x/b;
                x%=b;
        }
        cout << ans;
}