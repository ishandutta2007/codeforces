#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e3+10;
int n,a[maxn][maxn],ans;

bool nt(int x)
{
    for (int i=2;i*i<=x;i++)
        if (x%i==0) return false;
    return true;
}

void out()
{
    cout<<ans<<endl;
    for (int i=1;i<n;i++)
        for (int j=i+1;j<=n;j++)
            if (a[i][j]) cout<<i<<" "<<j<<endl;
}

int main()
{
    cin>>n;
    a[1][n]=1;
    for (int i=1;i<n;i++) a[i][i+1]=1;
    int t=n;
    while (!nt(t)) t++;
    ans=t;
    t-=n;
    for (int i=1;i<=t;i++) a[i][i+n/2]=1;
    out();
    return 0;
}