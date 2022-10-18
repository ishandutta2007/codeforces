#include <bits/stdc++.h>

#define fin freopen("rsq.in","r",stdin)
#define fout freopen("rsq.out","w",stdout)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sqr(x) ((x)*(x))
#define elif else if
#define I "%d"
#define II "%d%d"
#define III "%d%d%d"
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

#ifdef WIN32
    #define L "%I64d"
#else
    #define L "%lld"
#endif

using namespace std;

typedef unsigned long long ull;
typedef pair <int,int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <pii> vii;
typedef map <int,int> mii;
typedef long long ll;
typedef long double ld;

const ll maxll=numeric_limits<ll>::max();
const int maxint=numeric_limits<int>::max();
const ll md=1e9+7;
const ld eps=1e-6;

double a[10][10];
int n,k;
int ans=0;

void rec(int i,int j,double w)
{
    if (ans>=n*(n+1)/2) return;
    //cout<<i<<" "<<j<<" "<<w<<"\n";
    if (w==0) return;
    if (i==n-1)
    {
        if (a[i][j]<1.0&&a[i][j]+w>=1.0) ans++;
        a[i][j]=min(a[i][j]+w,1.0);
        return;
    }
    if (a[i][j]<1)
    {
        if (a[i][j]+w>=1)
        {
            w-=1.0-a[i][j];
            a[i][j]=1.0;
            ans++;
            rec(i+1,j,w/2);
            rec(i+1,j+1,w/2);
        }
        else a[i][j]=min(a[i][j]+w,1.0);
    }
    else
    {
        rec(i+1,j,w/2);
        rec(i+1,j+1,w/2);
    }
}

int main()
{
    cin>>n>>k;
    for (int t=0;t<k;t++)
    {
        rec(0,0,1.0);
        /*
        cout<<t+1<<"\n";
        for (int i=0;i<10;i++)
        {
            for (int j=0;j<=i;j++)
                cout<<a[i][j]<<" ";
            cout<<"\n";
        }
        */
    }
    //for (int i=0;i<10;i++)
        //for (int j=0;j<10;j++)
            //if (a[i][j]>=1) ans++;
    cout<<ans;
    return 0;
}