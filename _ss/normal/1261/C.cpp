#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll maxn=1e6+10,mod=1e9+7,inf=1e18;
vector<int> a[maxn],ps[maxn];
int n,m;

bool check(int x,int y,int siz)
{
    if (x+siz>n || x-siz<1 || y+siz>m || y-siz<1) return false;
    int x1=x-siz,x2=x+siz,y1=y-siz,y2=y+siz;
    return (ps[x2][y2]-ps[x1-1][y2]-ps[x2][y1-1]+ps[x1-1][y1-1]==(2*siz+1)*(2*siz+1));
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        a[i].resize(m+2,0);
        ps[i].resize(m+2,0);
        char ch;
        for (int j=1;j<=m;j++) cin>>ch,a[i][j]=(ch=='X');
    }
    a[0].resize(m+2,0);
    a[n+1].resize(m+2,0);
    ps[0].resize(m+2,0);
    ps[n+1].resize(m+2,0);
    int siz=min(m,n);
    for (int i=1;i<=n;i++)
    {
        int len=0;
        for (int j=1;j<=m;j++)
            if (a[i][j]) len++;
            else
            {
                if (len) siz=min(len,siz);
                len=0;
            }
        if (len) siz=min(len,siz);
    }

    for (int j=1;j<=m;j++)
    {
        int len=0;
        for (int i=1;i<=n;i++)
            if (a[i][j]) len++;
            else
            {
                if (len) siz=min(len,siz);
                len=0;
            }
        if (len) siz=min(len,siz);
    }
    siz=(siz-1)/2;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) ps[i][j]=ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1]+a[i][j];
    cout<<siz<<"\n";
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++)
        {
            if (check(i,j,siz)) cout<<"X";
            else cout<<".";
        } cout<<"\n"; }
    return 0;
}