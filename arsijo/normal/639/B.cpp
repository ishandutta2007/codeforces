#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
#define ld long double
#define ll long long
#define sqr(a) (a)*(a)
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define inf (int)1e9
#define pi pair<int,int>
#define y1 fdfs
using namespace std;
inline void read(int &x){x = 0;while(1){char ch = getchar();if(ch==' '||ch=='\n') break;x = x*10 + ch - '0';}}
inline void write(int x){char wr[12];int k = 0;if(!x) ++k,wr[k] = '0';while(x){++k;wr[k] = char(x%10+'0');x/=10;}for(int i=k;i>=1;--i)putchar(wr[i]);}
const int N = 1e5 + 5;
int n,d,h;
int last = 1;
vector<pair<int,int> > ans;
int mx, V;
vector<int> a[N];
void dfs(int v,int gl = 0,int pr = -1)
{
    if(gl>mx) mx = gl,V = v;
    for(int i=0;i<a[v].size();++i)
    {
        int to = a[v][i];
        if(to==pr) continue;
        dfs(to,gl+1,v);
    }
}
void dfs2(int v,int gl = 0,int pr = -1)
{
    if(gl>mx) mx = gl,V = v;
    for(int i=0;i<a[v].size();++i)
    {
        int to = a[v][i];
        if(to==pr) continue;
        dfs2(to,gl+1,v);
    }
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin>>n>>d>>h;
    if(d>h+h) return cout<<-1,0;
    if(d<h) return cout<<-1,0;
    for(int i=1;i<=h;++i)
        ans.pb(mp(i,i+1)),last = i + 1;
    if(h!=d)
    {
        int x = h;
        int X = 1;
        int Y = last + 1;
        while(x<d)
        {
            ans.pb(mp(X,Y));
            X = Y;
            Y = Y + 1;
            ++x;
        }
      //  ++Y;
        while(ans.size()<n-1)
        {
            ans.pb(mp(1,Y));
            ++Y;
        }
    }else{
        int Y = last + 1;
        --last;
        while(ans.size()<n-1)
            ans.pb(mp(last,Y)),++Y;
    }
    if(ans.size()!=n-1) return cout<<-1,0;
    for(int i=0;i<ans.size();++i)
        if(ans[i].x>n||ans[i].y>n) return cout<<-1,0;
    for(int i=0;i<ans.size();++i)
    {
        int x = ans[i].x;
        int y = ans[i].y;
        a[x].pb(y);
        a[y].pb(x);
    }
    mx = -1;
    dfs(1);
    if(mx!=h) return cout<<-1,0;
    mx = -1;
    dfs2(V);
    if(mx!=d) return cout<<-1,0;
    for(int i=0;i<ans.size();++i)
        cout<<ans[i].x<<' '<<ans[i].y<<"\n";

}