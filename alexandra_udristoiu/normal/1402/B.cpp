#include <bits/stdc++.h>

using namespace std;

long long ans;

void solve(long long n, int p) {
    if(n==0) return;
    if(n%2 == 1) {
        if(p == 0) ans++;
        solve(n - 1, 1 - p);
    }
    else {
        if((n/2)%2==0 && n != 4) {
            if(p == 0) ans++;
            solve(n - 1, 1 - p);
        }
        else {
            if(p == 0) ans += n/2;
            solve(n/2, 1 - p);
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    long long n;
    while(t--) {
        scanf("%lld", &n);
        ans = 0;
        solve(n, 0);
        printf("%lld\n",ans);
    }
    return 0;
}