#include <iostream>
#include <string>

#define M 120
#define N 60
#define INF 1000000000

using namespace std;

string s;
long n,ll[M][N],lr[M][N],rr[M][N],rl[M][N];

void ini(void){
    for (long i=0; i<N; ++i)
    for (long j=0; j<M; ++j){
        ll[j][i]=-INF;
        lr[j][i]=-INF;
        rr[j][i]=INF;
        rl[j][i]=INF;
    }
    ll[0][n]=0;
    rl[0][n]=0;
}

void din(long f){
    bool p=(s[f-1]=='F');
    for (long i=0; i<=n; ++i)
    for (long j=0; i+j<=n; ++j)
    if ((j%2==1)^p){
        ll[f][i]=max(ll[f][i],(ll[f-1][i+j]+1));
        lr[f][i]=max(lr[f][i],(lr[f-1][i+j]-1));
        rl[f][i]=min(rl[f][i],(rl[f-1][i+j]+1));
        rr[f][i]=min(rr[f][i],(rr[f-1][i+j]-1));
    }
    else{
        ll[f][i]=max(ll[f][i],lr[f-1][i+j]);
        lr[f][i]=max(lr[f][i],ll[f-1][i+j]);
        rl[f][i]=min(rl[f][i],rr[f-1][i+j]);
        rr[f][i]=min(rr[f][i],rl[f-1][i+j]);
    }
}

long abs(long x){
    if (x<0)
    x=-x;
    if (x>M)
    x=-INF;
    return x;
}

long ans(long x, long y, long z, long w){
    x=max(x,y);
    x=max(x,z);
    x=max(x,w);
    return x;
}

int main()
{
    long len;
    cin>>s>>n;
    len=s.length();
    ini();
    for (long i=1; i<=len; ++i)
    din(i);
    /*cout<<ll[len][0]<<endl;
    cout<<lr[len][0]<<endl;
    cout<<rl[len][0]<<endl;
    cout<<rr[len][0]<<endl;*/
    cout<<ans(abs(ll[len][0]),
              abs(lr[len][0]),
              abs(rl[len][0]),
              abs(rr[len][0]));
    return 0;
}