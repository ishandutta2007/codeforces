#include <iostream>
#include <algorithm>
#include <vector>

#define f first
#define s second
#define mp make_pair
#define M 1010
#define INF 1000000000000000000LL
#define long long long

using namespace std;

vector<int> f[M];
long n,m,c[M][M],s=0,t[M],k[M],bs=0,bt=0;
double d[M],h[M];
pair<int,int> p[M];
bool r[M];

void read(void){
    cin>>n>>m;
    for (int i=0; i<m; ++i){
        cin>>k[i];
        f[i].resize(k[i]);
        for (int j=0,x; j<k[i]; ++j){
            cin>>x;
            f[i][j]=x;
            p[s++]=mp(x,i);
        }
        sort(f[i].begin(),f[i].end());
    }
    sort(p,p+s);
}

void pre(void){
    for (int i=0; i<M; ++i)
    c[i][0]=1;
    for (int i=1; i<M; ++i)
    for (int j=1; j<=i; ++j){
        c[i][j]=c[i-1][j]+c[i-1][j-1];
        if (c[i][j]>INF)
        c[i][j]=INF;
    }
}

void make(void){
    int l=p[s-n].f;
    for (int i=s-1; i>=s-n && p[i].f>l; --i)
    t[p[i].s]++;
    
    for (int i=0; i<s; ++i)
    if (p[i].f==l)
    r[p[i].s]=1;
    
    for (int i=s-1; i>=s-n; --i)
    if (p[i].f==l)
    bt++;
    
}

void kill(void){
    h[0]=1.0;
    for (int i=0; i<m; ++i){
        for (int j=t[i]; j<=n; ++j)
        d[j]=h[j-t[i]]/c[k[i]][t[i]];
        
        if (r[i]){
            for (int j=t[i]+1; j<=n; ++j)
            d[j]+=(h[j-t[i]-1]/c[k[i]][t[i]+1]);
            bs++;
            if (bs>bt)
            for (int j=0; j<=n; ++j)
            d[j]*=(1.0-1.0*bt/bs);
        }
            
        
        for (int j=0; j<=n; ++j)
        h[j]=d[j],d[j]=0;
    }
    cout.precision(11);
    cout<<fixed<<h[n]<<"\n";
}

int main()
{
    pre();
    read();
    make();
    kill();
    return 0;
}