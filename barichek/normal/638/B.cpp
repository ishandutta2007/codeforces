#include <bits/stdc++.h>

#define fin freopen("number.in", "r", stdin)
#define fout freopen("number.out", "w", stdout)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define tin int timer=clock()
#define tout printf(I,clock()-timer)
#define sqr(x) (x)*(x)
#define elif else if
#define maxint 2147483647
#define pi M_PI
#define C "%c"
#define I "%d"
#define II "%d%d"
#define III "%d%d%d"
#define L "%lld"
#define LL "%lld%lld"
#define LLL "%lld%lld%lld"
#define D "%lf"
#define DD "%lf%lf"
#define DDD "%lf%lf%lf"
#define mp make_pair
#define pb push_back
#define sec second
#define fir first

using namespace std;

typedef pair <int,int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <pii> vii;
typedef map <int,int> mii;
typedef long long ll;

int n;
string a[10000];
struct
{
    int from,to;
    bool want,use;
} ver[1000];

int main()
{
    //fast;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<n;i++)
    {
        if (a[i].length()==1)
        {
            ver[a[i][0]].want=true;
            continue;
        }
        for (int j=0;j<a[i].length();j++)
            if (j==0) ver[a[i][j]].to=a[i][j+1], ver[a[i][j]].want=true;
            elif (j==a[i].length()-1) ver[a[i][j]].from=a[i][j-1], ver[a[i][j]].want=true;
            else ver[a[i][j]].from=a[i][j-1], ver[a[i][j]].to=a[i][j+1], ver[a[i][j]].want=true;
    }
    bool ok=true;
    while (ok)
    {
        int now;
        ok=false;
        for (int i='a';i<='z';i++)
            if (ver[i].want&&!ver[i].use&&ver[i].from==0)
            {
                now=i;
                ok=true;
                break;
            }
        if (!ok) break;
        while (ok)
        {
            printf(C,now);
            ver[now].use=true;
            if (ver[now].to==0) break;
            now=ver[now].to;
        }
    }
    return 0;
}