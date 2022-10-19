#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
        long long n, s=1, wyn=0, z=0;
        cin >> n;
        rep(i, n) {
                long long a;
                cin >> a;
                if(a<0) {
                        wyn+=abs(a+1);
                        a=-1;
                        s*=a;
                } else if(a>0) {
                        wyn+=abs(1-a);
                        a=1;
                } else ++z;
        }
        if(s==-1) if(z>0) { --z; ++wyn; } else wyn+=2;
        cout << wyn+z;
}