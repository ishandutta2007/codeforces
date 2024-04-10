#include <iostream>
#include <string>

#define pri 81
#define M 5000222
#define long long long

using namespace std;

long n,hs[M],hr[M],p[M],f[M];
string s,r;

void read(void){
    cin>>s;
    n=s.length();
    r.resize(n);
    for (long i=0; i<n; ++i)
    r[n-i-1]=s[i];
}

void hash(void){
    p[0]=1;
    for (long i=1; i<M; ++i)
    p[i]=p[i-1]*pri;
    hs[0]=s[0];
    hr[0]=r[0];
    for (long i=1; i<n; ++i){
        hs[i]=hs[i-1]+p[i]*s[i];
        hr[i]=hr[i-1]+p[i]*r[i];
    }
}

bool ispal(long r){
    return hs[r]*p[n-r-1]==hr[n-1]-hr[n-1-r-1];
}

void calcf(void){
    f[0]=1;
    for (long i=1; i<n; ++i)
    if (ispal(i))
    f[i]=f[(i-1)/2]+1;
    else
    f[i]=0;
    long s=0;
    for (long i=0; i<n; ++i)
    s+=f[i];
    cout<<s;
}

int main()
{
    read();
    hash();
    calcf();

    return 0;
}