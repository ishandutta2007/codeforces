#include <iostream>
#include <algorithm>



#define M 100100
#define f first
#define s second
#define T 3200
#define mp make_pair

using namespace std;

long n,m,a[M],b[M],p[T],c=0,x[M],y[M];
bool u[T];
pair<long,long> d[M],h[M];

void pre(void){
    for (long i=2; i<T; ++i)
    if (!u[i]){
        p[c++]=i;
        for (long j=i; j<T; j+=i)
        u[j]=1;
    }
}

void read(void){
    cin>>n>>m;
    for (long i=0; i<n; ++i){
        cin>>a[i];
        x[i]=1;
    }
    for (long i=0; i<m; ++i){
        cin>>b[i];
        y[i]=1;
    }
}

void clear(void){
    long u,d;
    for (long k=0,t; k<c; ++k){
        t=p[k];

        for (long j=0,i=0;i<n && j<m;){
            while (a[i]%t==0 && b[j]%t==0){
                a[i]/=t;
                b[j]/=t;
            }
            while(i<n && a[i]%t!=0)
            ++i;
            while (j<m && b[j]%t!=0)
            ++j;
        }

        for (long i=0; i<n; ++i)
        while (a[i]%t==0){
            a[i]/=t;
            x[i]*=t;
        }

        for (long i=0; i<m; ++i)
        while (b[i]%t==0){
            b[i]/=t;
            y[i]*=t;
        }

    }
}

void sort_it(void){
    for (long i=0;i<n; ++i)
    d[i]=mp(a[i],i);
    for (long i=0; i<m; ++i)
    h[i]=mp(b[i],i);
    sort(d,d+n);
    sort(h,h+m);
    for (long i=0,j=0; i<n && j<m;){
        while (j<m && h[j].f<d[i].f)
        ++j;
        if (h[j].f==d[i].f){
            h[j].f=1;
            d[i].f=1;
            ++j;
        }
        ++i;
    }
}

int main()
{
    pre();
    read();
    clear();
    sort_it();
    cout<<n<<" "<<m<<"\n";
    for (long i=0; i<n; ++i)
    cout<<x[d[i].s]*d[i].f<<" ";
    cout<<"\n";
    for (long i=0; i<m; ++i)
    cout<<y[h[i].s]*h[i].f<<" ";
    return 0;
}