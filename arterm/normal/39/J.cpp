#include <iostream>
#include <string>

#define pri 243
#define M 1101010

using namespace std;

long n,hs[M],ht[M],ans=0,p[M],f[M];
string s,t;

void read(void){
    cin>>s>>t;
    n=t.length();
}

void hash(void){
    p[-0]=1;
    for (long i=1; i<M; ++i)
    p[i]=pri*p[i-1];
    hs[0]=s[0];
    ht[0]=t[0];
    for (long i=1; i<n; ++i)
    ht[i]=ht[i-1]+p[i]*t[i];
    for (long i=1; i<=n; ++i)
    hs[i]=hs[i-1]+p[i]*s[i];
}

bool che(long h){
    if (!h)
    return hs[n]-hs[0]==pri*ht[n-1];
    return hs[h-1]==ht[h-1] && hs[n]-hs[h]==pri*(ht[n-1]-ht[h-1]);
}

int main()
{
    read();
    hash();
    for (long i=0; i<=n; ++i)
    if (che(i))
    f[ans++]=i;
    cout<<ans<<"\n";
    for (long i=0; i<ans; ++i)
    cout<<f[i]+1<<"\n";
    return 0;
}