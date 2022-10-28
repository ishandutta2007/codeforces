#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
 
template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }
 
const int N=2e5+5;

int n;
int x[N];
char c[N];
int cache[N][2][2][2];

int dp(int i, int r, int b, int rb, int prevr=-1e15, int prevb=-1e15, int pg=-1e15)
{
    if(i==n+1)
    {
        if(pg>0 && (!r || !b))
            return 1e15;
        return 0;
    }
    int &ans=cache[i][r][b][rb];
    if(ans!=-1)
    {
        return ans;
    }
    ans=1e15;
    if(c[i] == 'P')
    {
        if(pg < -1e9)
        {
            ans = dp(i+1, r, b, rb, prevr, prevb, x[i]);
            ans = min(ans, x[i] - prevb + dp(i+1, r, 1, rb, prevr, prevb, x[i]));
            ans = min(ans, x[i] - prevr + dp(i+1, 1, b, rb, prevr, prevb, x[i]));
            ans = min(ans, x[i] - prevr + x[i] - prevb + dp(i+1, 1, 1, rb, prevr, prevb, x[i]));
        }
        else
        {
            ans = x[i] - pg + dp(i+1, r, b, rb, prevr, prevb, x[i]);
            ans = min(ans, x[i] - pg + x[i] - prevb + dp(i+1, r, 1, rb, prevr, prevb, x[i]));
            ans = min(ans, x[i] - pg + x[i] - prevr + dp(i+1, 1, b, rb, prevr, prevb, x[i]));
            ans = min(ans, x[i] - pg + x[i] - prevr + x[i] - prevb + dp(i+1, 1, 1, rb, prevr, prevb, x[i]));
            if(r and b)
                ans = min(ans, x[i] - prevr + x[i] - prevb + dp(i+1, 1, 1, rb, prevr, prevb, x[i]));
        }
    }
    else if(c[i] == 'R')
    {
        if(r)
        {
            ans = dp(i+1, 0, b, rb, x[i], prevb, pg);
            ans = min(ans, x[i] - prevb + dp(i+1, 0, b, 1, x[i], prevb, pg));
            ans = min(ans, x[i] - pg + dp(i+1, 1, b, rb, x[i], prevb, pg));
            ans = min(ans, x[i] - prevb + x[i] - pg + dp(i+1, 1, b, 1, x[i], prevb, pg));
        }
        ans = min(ans, x[i] - prevr + dp(i+1, r, b, rb, x[i], prevb, pg));
        ans = min(ans, x[i] - prevr + x[i] - pg + dp(i+1, 1, b, rb, x[i], prevb, pg));
        ans = min(ans, x[i] - prevr + x[i] - prevb + dp(i+1, r, b, 1, x[i], prevb, pg));
        ans = min(ans, x[i] - prevr + x[i] - pg + x[i] - prevb + dp(i+1, 1, b, 1, x[i], prevb, pg));
    }
    else
    {
        if(b)
        {
            ans = dp(i+1, r, 0, rb, prevr, x[i], pg);
            ans = min(ans, x[i] - prevr + dp(i+1, r, 0, 1, prevr, x[i], pg));
            ans = min(ans, x[i] - pg + dp(i+1, r, 1, rb, prevr, x[i], pg));
            ans = min(ans, x[i] - prevr + x[i] - pg + dp(i+1, r, 1, 1, prevr, x[i], pg));
        }
        ans = min(ans, x[i] - prevb + dp(i+1, r, b, rb, prevr, x[i], pg));
        ans = min(ans, x[i] - prevb + x[i] - pg + dp(i+1, r, 1, rb, prevr, x[i], pg));
        ans = min(ans, x[i] - prevb + x[i] - prevr + dp(i+1, r, b, 1, prevr, x[i], pg));
        ans = min(ans, x[i] - prevb + x[i] - pg + x[i] - prevr + dp(i+1, r, 1, 1, prevr, x[i], pg));
    }
    return ans;
}

int32_t main()
{
    IOS;
    memset(cache, -1, sizeof(cache));
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>c[i];
    }
    int ans=dp(1, 1, 1, 0);
    cout<<ans;
    return 0;
}