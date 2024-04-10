#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=5e5+5;
const int M=5e3+5;

int n, k;
int a[N], dp[3][M];

typedef struct dat
{
    int diff, start, end;
}data;

data v[N];

bool comp(data &d1, data &d2)
{
    return d1.diff<d2.diff;
}

bool comp2(data &d1, data &d2)
{
    return d1.start<d2.start;
}

int32_t main()
{
    IOS;
    cin>>k>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1, a+n+1);
    for(int i=1;i<=n-1;i++)
    {
        v[i].diff=a[i+1]-a[i];
        v[i].start=a[i];
        v[i].end=a[i+1];
    }
    sort(v+1, v+n, comp);
    n=min(n-1, 3*k);
    sort(v+1, v+n+1, comp2);
    for(int i=0;i<k;i++)
    {
        dp[(n+1)%3][i]=1e9;
    }
    dp[(n+1)%3][k]=0;
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<k;j++)
        {
            int &ans=dp[i%3][j];
            dp[i%3][j]=dp[(i+1)%3][j];
            if(i<n && v[i+1].start==v[i].end)
                ans=min(ans, v[i].diff + dp[(i+2)%3][j+1]);
            else
                ans=min(ans, v[i].diff + dp[(i+1)%3][j+1]);
        }
        dp[i%3][k]=0;
    }
    int ans=dp[1][0];
    cout<<ans;
    return 0;
}