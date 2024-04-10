#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli A,B;
int main() {
    scanf("%lld%lld",&A,&B);

    int cnt=0;
    for(int i=1;i<63;i++) {
        lli v=(1ll<<i)-1;
        for(int j=0;j<i-1;j++) {
            lli val = v ^ (1ll<<j);
            if(A<=val && val<=B) {
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    
    return 0;
}