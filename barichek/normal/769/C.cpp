#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define files_ds(name) freopen(name".dat","r",stdin); freopen(name".sol","w",stdout);
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

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

const vector<pii> moves={{-1,0},{+1,0},{0,-1},{0,+1}};

char a[ar][ar];
int dist[ar][ar];
int n,m,k;

bool ok(int a,int b)
{
    return min(a,b)>=0&&a<n&&b<m;
}

void bfs(int xx,int yy)
{
    for (int i=0;i<ar;i++)
        for (int j=0;j<ar;j++)
            dist[i][j]=1e9;
    dist[xx][yy]=0;
    queue<pii> q;
    q.push(mp(xx,yy));
    while (!q.empty())
    {
        pii now=q.front();
        q.pop();
        for (auto wh:moves)
            if (ok(now.fir+wh.fir,now.sec+wh.sec))
                if (a[now.fir+wh.fir][now.sec+wh.sec]!='*')
                    if (dist[now.fir+wh.fir][now.sec+wh.sec]>dist[now.fir][now.sec]+1)
                    {
                        dist[now.fir+wh.fir][now.sec+wh.sec]=dist[now.fir][now.sec]+1;
                        q.push(mp(now.fir+wh.fir,now.sec+wh.sec));
                    }
    }
}

main()
{
    string ans="";
    cin>>n>>m>>k;
    int xx,yy;
    if (k&1) return cout<<"IMPOSSIBLE", 0;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        {
            cin>>a[i][j];
            if (a[i][j]=='X')
                xx=i,
                yy=j;
        }
    bfs(xx,yy);
    while (ans.size()<k/2)
    {
        if (xx!=n-1&&a[xx+1][yy]!='*')
            xx++,
            ans+='D';
        elif (yy!=0&&a[xx][yy-1]!='*')
            yy--,
            ans+='L';
        elif (yy!=m-1&&a[xx][yy+1]!='*')
            yy++,
            ans+='R';
        elif (xx!=0&&a[xx-1][yy]!='*')
            xx--,
            ans+='U';
        else
            return cout<<"IMPOSSIBLE", 0;
    }
    while (ans.size()<k)
    {
        if (xx!=n-1&&a[xx+1][yy]!='*'&&dist[xx+1][yy]<k-ans.size())
            xx++,
            ans+='D';
        elif (yy!=0&&a[xx][yy-1]!='*'&&dist[xx][yy-1]<k-ans.size())
            yy--,
            ans+='L';
        elif (yy!=m-1&&a[xx][yy+1]!='*'&&dist[xx][yy+1]<k-ans.size())
            yy++,
            ans+='R';
        elif (xx!=0&&a[xx-1][yy]!='*'&&dist[xx-1][yy]<k-ans.size())
            xx--,
            ans+='U';
        else
            return cout<<"IMPOSSIBLE", 0;
    }
    cout<<ans<<"\n";
}

/*

9 7 18
*******
*..X***
*.*..**
*.**..*
*.***.*
*.**..*
*....**
*******
*******

*/