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
#define int long long

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
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

int cnt[ar][ar];

main()
{
    int n,m,k,x,y;
    cin>>n>>m>>k>>x>>y;
    if (n==1)
    {
        for (int j=1;j<=m;j++)
            cnt[1][j]+=k/m;
        for (int j=1;j<=k%m;j++)
            cnt[1][j]++;
    }
    else
    {
        int full_2=k/((2*n-2)*m);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                cnt[i][j]+=((i==1||i==n)?full_2:2*full_2);
        int cur=k%((2*n-2)*m);
        int xx=1;
        int yy=1;
        int where=1;
        while (cur--)
        {
            //cerr<<xx<<" "<<yy<<"\n";
            cnt[xx][yy]++;
            yy++;
            if (yy==m+1)
            {
                yy=1;
                xx+=where;
                if (xx==n+1)
                    xx=n-1,
                    where*=-1;
            }
        }
    }
    int max_=0;
    int min_=k+1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            max_=max(max_,cnt[i][j]),
            min_=min(min_,cnt[i][j]);
    cout<<max_<<" "<<min_<<" "<<cnt[x][y]<<"\n";
}