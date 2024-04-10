#include <iostream>
#include <algorithm>


#define INF 1000000000000000000LL;
#define long long long
#define M 100100
#define mp make_pair
#define s second
#define f first

using namespace std;

long n,h,c[M],del;
pair<long,long> a[M];

void read(void){
    cin>>n>>h;
    for (long i=0,x; i<n; ++i){
        cin>>x;
        a[i]=mp(x,i);
    }
    sort(a,a+n);
}

void calc(void){
    long p[10],b=1<<n,v,mi,ma,d,mb;
    d=4*INF;
    p[0]=1;
    for (long i=1; i<10; ++i)
    p[i]=2*p[i-1];

    for (long i=0; i<b; ++i){
        for (long x=0; x<n; ++x)
        for (long y=x+1; y<n; ++y){
            if ((i>>x)%2==(i>>y)%2)
            v=a[x].f+a[y].f;
            else
            v=a[x].f+a[y].f+h;
            if (x==0 && y==1)
            mi=ma=v;
            mi=min(mi,v);
            ma=max(ma,v);
        }

        if (ma-mi<d){
            d=ma-mi;
            mb=i;
        }
    }

    del=d;
    for (long x=0; x<n; ++x)
    if (mb&p[x])
    c[a[x].s]=1;
    else
    c[a[x].s]=2;


}


void solve(void){
    long mi,ma,del1,del2;
        c[a[0].s]=1;
        c[a[1].s]=1;
        c[a[n-1].s]=1;
        c[a[n-2].s]=1;
        ma=a[n-1].f+a[n-2].f;
        mi=a[0].f+a[1].f;
        del1=ma-mi;
        ma=max(ma,(a[n-1].f+a[0].f+h));
        mi=min((mi+h),(a[1].f+a[2].f));
        del2=ma-mi;
        if (del2<del1)
        c[a[0].s]=2;
        del=min(del1,del2);

    cout<<del<<endl;
    for (long i=0; i<n; ++i)
    if (c[i]>0)
    cout<<c[i]<<" ";
    else
    cout<<"1 ";

}

int main()
{
      //  cout<<INF;
    read();
    solve();
    return 0;
}