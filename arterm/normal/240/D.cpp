#include <fstream>
#include <string>
#include <algorithm>

#define M 100100

using namespace std;

ifstream cin ("input.txt");
ofstream cout("output.txt");

long n,m,l=1,r=1,ro,lo,u,f[2*M],v[2*M],c=0;
long a[M],b[M],p=0,d[2*M];
bool fl=1;


void read(void){
    cin>>n;
    for (long i=1; i<=n; ++i)
    cin>>a[i];
    cin>>m;
    for (long i=1; i<=m; ++i)
    cin>>b[i];
    l=n;
    r=m;
    u=n+m;
}

void doit(void){
    while (l>0 || r>0){
        while (l>0 && a[l]==p){
            f[u]=l;
            d[u]=p;
            //cout<<f[u]<<" ";
            u--;
            l--;
        }
        while (r>0 && b[r]==p){
            f[u]=r+n;
            d[u]=p;
            //cout<<f[u]<<" ";
            u--;
            r--;
        }
        /*if (l>0 || r>0){
            c++;
            v[c]=u;
            if (v[c]==0)
            v[c]=n+m;
        }*/
        if (p==0)
        p=1;
        else
        p=0;
    }
    f[n+m+1]=0;
    p=d[1];
    for (long i=1; i<=n+m;){
        while (i<=n+m && d[i]==p)
        ++i;
        p=d[i];
        c++;
        v[c]=i-1;
    }

    if (d[n+m]==0 && v[c]==n+m)
    c--;

    for (long i=1; i<=n+m; ++i)
    cout<<f[i]<<" ";
    cout<<"\n"<<c<<"\n";
    for (long i=1; i<=c; ++i)
    cout<<v[i]<<" ";
}

int main()
{
    read();
    //cout<<n<<" "<<m<<"\n";
    doit();
    return 0;
}