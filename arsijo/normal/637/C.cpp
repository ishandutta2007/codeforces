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
const int N = 1015,M = 1e6;
int n;
string s[N],t;
bool p;
bool used[M + 10];
void rec(int pos,int K)
{
    if(!p) return;
    if(pos==5)
    {
        int x = 0;
        for(int i=0;i<6;++i)
            x = x*10 + t[i] - '0';
        if(used[x])
        {
            p = 0;
            return;
        }
        used[x] = 1;
        return;
    }
    rec(pos+1,K);
    if(K)
    {
        char ch = t[pos+1];
        for(int i=0;i<10;++i)
        {
            t[pos+1] = char(i+'0');
            if(t[pos+1]==ch) continue;
            rec(pos+1,K-1);
        }
        t[pos+1] = ch;
    }
}
bool solve(int K)
{
    p = 1;
    memset(used,0,sizeof used);
    for(int i=1;i<=n;++i){
        t = s[i];
        rec(-1,K);
    }
    return p;
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>s[i];
    if(n==1) return cout<<6,0;
    for(int K = 0; K <= 6 ; ++K)
        if(!solve(K)) return cout<< K - 1 ,0;
}