#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl

const int Maxn=1000*10+100;
vector<int> adj[Maxn];
vector<string> s;
bool see[Maxn];

void add(int x,int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

void dfs(int x, int t , int m)
{
    see[x]=true;
    int p1=x/m,p2=x%m;
    if(t==1)
    {
        s[p1][p2]='B';
    }
    else
    {
        s[p1][p2]='W';
    }

    for(int u:adj[x])
    {
        if(!see[u])
        {
            dfs(u,1-t,m);
        }
    }
}

int main()
{
    int n,m;
    cin >> n >> m;

    s.resize(n);
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
    }

    vector<int> to_dfs;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='.')
            {
                to_dfs.push_back(i*m+j);

                if(i!=0)
                {
                    if(s[i-1][j]=='.')
                    {
                        add(i*m+j,(i-1)*m+j);
                    }
                }
                if(j!=0)
                {
                    if(s[i][j-1]=='.')
                    {
                        add(i*m+j,i*m+j-1);
                    }
                }

                if(i!=n-1)
                {
                    if(s[i+1][j]=='.')
                    {
                        add(i*m+j,(i+1)*m+j);
                    }
                }
                if(j!=m-1)
                {
                    if(s[i][j+1]=='.')
                    {
                        add(i*m+j,i*m+j+1);
                    }
                }
            }
        }
    }

    for(int i:to_dfs)
    {
        if(!see[i])
        {
            dfs(i,1 , m);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout << s[i][j];
        }
        cout << endl;
    }
}