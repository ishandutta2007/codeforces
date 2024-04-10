#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e3+10;
int n,m,a[maxn],s[maxn][6];

void read()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        char ch=getchar();
        for (int j=1;j<=m;j++)
        {
            ch=getchar();
            s[j][ch-'A'+1]++;
        }
    }
    for (int i=1;i<=m;i++) cin>>a[i];
}

void process()
{
    int ans=0;
    for (int i=1;i<=m;i++)
    {
        int t=0;
        for (int j=1;j<=5;j++) t=max(t,s[i][j]);
        ans+=t*a[i];
    }
    cout<<ans;
}

int main()
{
    read();
    process();
    return 0;
}