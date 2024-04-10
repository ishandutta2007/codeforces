#include <iostream>
#include <string>

#define M 1000100
#define long long long
#define p 1000000007

using namespace std;

long n,k,t[3][M],d[M],r[M],x[M];
char s[M];

void read(void){
    cin>>n>>k;
    for (long i=1; i<=n; ++i){
        cin>>s[i];
        t[0][i]=t[0][i-1];
        t[1][i]=t[1][i-1];
        t[2][i]=t[2][i-1];
        if (s[i]=='B')
        t[1][i]++;
        if (s[i]=='W')
        t[0][i]++;
        if (s[i]=='X')
        t[2][i]++;
    }
    s[0]='F';
}

bool pos(long f, long l){
    return t[f][l+k]==t[f][l];
}

void din(void){
    d[0]=1;
    for (long i=1; i<=k; ++i){
        d[i]=d[i-1];
        if (s[i]=='X')
        d[i]*=2,d[i]%=p;
    }
    if (pos(0,0))
    d[k]--,d[k]%=p;
    for (long i=k+1; i<=n; ++i){
        d[i]=d[i-1];
        if (s[i]=='W')
        continue;
        if (s[i]=='X')
        d[i]*=2,d[i]%=p;

        if (pos(0,i-k) && s[i-k]!='B')
        d[i]-=d[i-k-1],d[i]%=p;

    }


    r[n+1]=1;
    for (long i=n; i>n-k; --i){
        r[i]=r[i+1];
        if (s[i]=='X')
        r[i]*=2,r[i]%=p;
    }
    if (pos(1,n-k))
    r[n-k+1]--,r[n-k+1]%=p;
    for (long i=n-k; i>0; --i){
        r[i]=r[i+1];
        if (s[i]=='B')
        continue;
        if (s[i]=='X')
        r[i]*=2,r[i]%=p;
        if (pos(1,i-1) && s[i+k]!='W')
        r[i]-=r[i+k+1],r[i]%=p;
    }

    //for (long i=1; i<=n; ++i)
    //cout<<r[i]<<" ";

}

void accum(void){
    x[n-k+1]=pos(1,n-k);
    for (long i=n-k; i>0; --i){
        x[i]=x[i+1];
        if (s[i]=='X')
        x[i]*=2,x[i]%=p;
        if (pos(1,i-1) && s[i+k]!='W')
        x[i]+=r[i+k+1],x[i]%=p;
    }
}

void kill(void){
    long ans=0;
    for (long i=k; i+k<=n; ++i,ans%=p)
    if (pos(0,i-k) && s[i-k]!='B')
    if (i-k-1>=0)
    ans=ans+d[i-k-1]*x[i+1];
    else
    ans=ans+x[i+1];
    if (ans<0)
    ans+=p;
    cout<<ans<<"\n";
}

int main()
{
    read();
    din();
    accum();
    kill();
    return 0;
}