#include <iostream>
#include <algorithm>

#define M 100100
#define f first
#define s second
#define mp make_pair
#define long long long

using namespace std;

long n,k,ans=0;
long d[M],c[M];
pair<long,long> p[M];

void read(void){
    cin>>n>>k;
    for (long x,y,i=0; i<n; ++i){
        cin>>x;
        y=0;
        if (k!=1)
        while (x%k==0){
            x/=k;
            y++;
        }
        p[i]=mp(x,y);
    }
    sort(p,p+n);
}

void kill(void){
    if (k!=1)
    for (long i=0,j; i<n; ){
        j=i;

        for (long h=0; h<33;  ++h)
        d[h]=0;

        while (j<n && p[i].f==p[j].f){
            d[p[j].s]++;
            j++;
        }
        c[0]=d[0];
        c[1]=max(d[1],d[0]);
        for (long h=2; h<33; ++h)
        c[h]=max((d[h]+c[h-2]),c[h-1]);
        ans+=c[32];

        i=j;

    }

    if (k==1)
    ans=n;

    cout<<ans<<"\n";

}

int main()
{
    read();
    kill();
    return 0;
}