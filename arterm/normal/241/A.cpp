#include <iostream>

#define long long long
#define M 1010

using namespace std;

long m,k,d[M],s[M],ps[M],pd[M];

void read(void){
    cin>>m>>k;
    for (long i=1; i<=m; ++i){
        cin>>d[i];
        pd[i]=d[i]+pd[i-1];
    }
    pd[m+1]=pd[m];
    for (long i=1; i<=m; ++i){
        cin>>s[i];
        ps[i]=s[i]+ps[i-1];
    }
}

bool che(long l, long r, long t){
    for (long i=l; i<r; ++i){
        t+=s[i];
        t-=d[i];
        if (t<0)
        return 0;
    }
    return 1;
}

long emu(long l, long r, long t){
    for (long i=l; i<r; ++i){
        t+=s[i];
        t-=d[i];
    }
    return t;
}

long bin(long i, long j, long t){
    long l=0,r=1010101,m;
    while (l<r){
        m=(l+r)/2;
        if  (che(i,j,t+m*s[i]))
        r=m;
        else
        l=m+1;
    }
    return l;
}

void solve(void){
    long ans=0,r=0,t;
    for (long w,j,i=1; i<=m;){
        w=0;
        for (j=i;j<=m && s[j]<=s[i];++j)
        w+=d[j];
        /*if (r<w){
            t=(w-r+s[i]-1)/s[i];
            ans+=(k*(t-1));
            r=r+t*s[i];
        }*/
        t=bin(i,j,r);
        //cout<<i<<" "<<j<<" --"<<t<<":"<<w<<"\n";
        ans+=(k*t);
        r=r+t*s[i];
        r=emu(i,j,r);
        i=j;
        ans+=w;

    }
    cout<<ans;
}

int main()
{
    read();
    solve();
    return 0;
}