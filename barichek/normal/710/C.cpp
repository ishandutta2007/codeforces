#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int maxint=numeric_limits<int>::max();
const ll maxll=numeric_limits<ll>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ll md=1e9+7;
const ld eps=1e-6;

///---program start---///

bool use[ar][ar];
int ans[ar][ar];
int ans1[ar][ar];
int n;

bool ok(int a)
{
    return a>=1&&a<=n;
}

main()
{
    cin>>n;
    int x=n-1;
    int y=n;
    int cur=1;
    int ukaz=1;
    int sx=x;
    int sy=y;
    while (cur<n*n/2+1-n/2)
    {
        x=sx;
        y=sy;
        sx--;
        sy--;
        ukaz=1;
        while (true)
        {
            ans[x][y]=cur++;
            use[x][y]=true;
            if (ok(x-1)&&!use[x-1][y]&&ukaz==1) x--;
            elif (ok(y-1)&y-1>x&&!use[x][y-1]&&ukaz==0) y--;
            elif (x==n-y+1&&ukaz==1) y--, ukaz=0;
            else break;
        }
    }
    for (int i=n;i>=1;i--)
        ans[i][i]=cur++;
    if (n%4==1) cur++;
    sx=2;
    sy=1;
    while (cur<n*n)
    {
        x=sx;
        y=sy;
        sx++;
        sy++;
        ukaz=1;
        while (true)
        {
            //cout<<x<<" "<<y<<" "<<cur<<" !\n";
            ans[x][y]=cur++;
            use[x][y]=true;
            if (ok(x+1)&&!use[x+1][y]&&ukaz==1) x++;
            elif (ok(y+1)&&y+1<x&&!use[x][y+1]&&ukaz==0) y++;
            elif (x==n-y+1&&ukaz==1) y++, ukaz=0;
            else break;
        }
    }
    if (n%4==1)
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                ans1[i][j]=ans[i][j];
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                ans[i][j]=ans1[j][i];
    }
    for (int j=n;j>=1;j--)
        for (int i=1;i<=n;i++)
            cout<<(ans[i][j]>n*n?n*n/2+1+n/2+1:ans[i][j])<<(i==n?"\n":" ");
}