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
const int N = 1e5;
int n,k,a,b,c,d;
vector<int> v;
bool used[N];
bool dd[1002][1002];
int s;
bool f(vector<int> v)
{
    for(int i=1;i<v.size();++i)
    {
        int x = v[i-1];
        int y = v[i];
        dd[x][y] = dd[y][x] = 1;
        if(x==a&&y==b) {
            cout<<-1;
            exit(0);
        }
        if(x==b&&y==a) {
            cout<<-1;
            exit(0);
        }
        if(x==c&&y==d) {
            cout<<-1;
            exit(0);
        }
        if(x==d&&y==c){
            cout<<-1;
            exit(0);
        }
    }
}
vector<int> X,Y;
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    cin>>a>>b>>c>>d;
    v.pb(a);
    v.pb(c);
    used[a] = used[c] = used[b] = used[d] = 1;
    while(1)
    {
        bool p = 0;
        for(int i=1;i<=n;++i)
            if(!used[i])
        {
            v.pb(i);
            used[i] = 1;
            p = 1;
        }
        if(!p) break;
    }
    v.pb(d);
    v.pb(b);
    for(int i=1;i<v.size();++i)
    {
        int x = v[i-1];
        int y = v[i];
        if(x==a&&y==b) return cout<<-1,0;
        if(x==b&&y==a) return cout<<-1,0;
        if(x==c&&y==d) return cout<<-1,0;
        if(x==d&&y==c) return cout<<-1,0;
    }
    for(int i=0;i<v.size();++i)
        X.pb(v[i]);
    Y.pb(v[1]);
    Y.pb(v[0]);
    //for(int i=1;i<(int)v.size()-2;++i)
        //Y.pb(v[i]);
    for(int i=2;i<v.size()-2;++i)
        Y.pb(v[i]);
    Y.pb(v.back());
    Y.pb(v[v.size()-2]);
    f(X);
    f(Y);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        s+=dd[i][j];
    s/=2;
    if(s>k) return cout<<-1,0;
    for(int i=0;i<X.size();++i)
        cout<<X[i]<<' ';
    cout<<"\n";
    for(int i=0;i<Y.size();++i)
        cout<<Y[i]<<' ';

}