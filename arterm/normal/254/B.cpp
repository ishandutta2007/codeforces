#include <fstream>

using namespace std;

ifstream cin ("input.txt");
ofstream cout("output.txt");



long d[]={31,28,31,30,31,30,31,31,30,31,30,31};
long f[1000],n;

long num(long m, long h){
    long s=0;
    for (long i=0; i+1<m; ++i)
    s+=d[i];
    s+=h;

    return s+200;
}


void read(void){
    cin>>n;
    for (long x,y,s,t,p,i=0; i<n; ++i){
        cin>>x>>y;
        cin>>p>>t;
        s=num(x,y);
        for (long i=1; i<=t; ++i)
        f[s-i]+=p;
    }
    long k=0;
    for (long i=0; i<1000; ++i)
    k=max(k,f[i]);
    cout<<k<<endl;
}

int main()
{
    read();
    return 0;
}