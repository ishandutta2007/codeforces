#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main() {
    lli n;
    scanf("%lld",&n);
    
    lli lo=0,up=1e8;
    while(up-lo>1) {
        lli md=(lo+up)>>1;
        if(md*(md+1)/2<n) lo=md;
        else up=md;
    }
    printf("%lld\n",n-(lo*(lo+1)/2));
    return 0;
}