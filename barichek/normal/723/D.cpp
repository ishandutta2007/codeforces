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
const ld eps=1e-10;

///---program start---///

const vector<pii> moves={{-1,0},{+1,0},{0,-1},{0,+1}};

int n,m,k;
char a[ar][ar];

bool ok(int a,int b)
{
    return a>=0&&a<n&&b>=0&&b<m;
}

bool use_up[ar][ar];
bool use_down[ar][ar];

int dfs_up(int x,int y)
{
    if (x==0||y==0||x==n-1||y==m-1) return 1e7;
    int res=1;
    use_up[x][y]=true;
    for (auto wh:moves)
        if (ok(x+wh.fir,y+wh.sec))
            if (a[x+wh.fir][y+wh.sec]=='.')
                if (!use_up[x+wh.fir][y+wh.sec])
                    res+=dfs_up(x+wh.fir,y+wh.sec);
    return res;
}

int dfs_down(int x,int y)
{
    int res=1;
    a[x][y]='*';
    use_down[x][y]=true;
    for (auto wh:moves)
        if (ok(x+wh.fir,y+wh.sec))
            if (a[x+wh.fir][y+wh.sec]=='.')
                if (!use_down[x+wh.fir][y+wh.sec])
                    res+=dfs_down(x+wh.fir,y+wh.sec);
    return res;
}

main()
{
    cin>>n>>m>>k;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>a[i][j];
    vector<pair<int,pii>> komp;
    komp.clear();
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (a[i][j]=='.')
                if (!use_up[i][j])
                {
                    int dop=dfs_up(i,j);
                    if (dop<=1e6) komp.pb(mp(dop,mp(i,j)));
                }
    sort(all(komp));
    int ans=0;
    int had=komp.size();
    for (int i=0;i<komp.size()&&had!=k;i++)
    {
        ans+=komp[i].fir;
        dfs_down(komp[i].sec.fir,komp[i].sec.sec);
        had--;
    }
    cout<<ans<<"\n";
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cout<<a[i][j]<<(j==m-1?"\n":"");
}