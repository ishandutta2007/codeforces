#include <bits/stdc++.h>

using namespace std;

#define int int64_t
int MOD = 1e9 + 7;
main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int a,b;
    cin>>a>>b;
    int ans=0;
    for(int i=1;i<b;i++)
    {
        int x = 2*(i*b+i)+i % MOD * b % MOD *(a-1);
        x%=MOD;
        int y = a;
        if(x%2) x+=MOD;
        x/=2;
        ans = (ans + x % MOD * y % MOD) % MOD;
    }
    cout<<ans<<endl;
}