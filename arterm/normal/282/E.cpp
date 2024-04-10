#include <iostream>

#define long long long
#define N 41
#define M 100100

using namespace std;

struct data{
    int link[2];
    bool end;//of the world!
} b[N*M];

long p[N],a[M],n,s=1;

void pre(void){
    p[0]=1;
    for (int i=1; i<N; ++i)
    p[i]=p[i-1]<<1;
}

void read(void){
    cin>>n;
    for (int i=1; i<=n; ++i)
    cin>>a[i];
}

void add(long x){
    long i=N-1,t=1;
    while (i>=0){
        int k=(p[i]&x)==p[i] ? 1:0;

        if (b[t].link[k]==0){
            s++;
            b[t].link[k]=s;
        }

        t=b[t].link[k];

        --i;
    }
    b[t].end=1;
}

long que(long x){
    long i=N-1,t=1,ans=0;
    while (i>=0){
        int k=(p[i]&x)==p[i] ? 0:1;

        if (b[t].link[k]==0)
        t=b[t].link[1-k];
        else
        t=b[t].link[k],ans+=p[i];

        --i;
    }
    return ans;
}

void kill(void){
    long t=0,y=0,ans=0;
    for (int i=1; i<=n; ++i)
    t^=a[i];
    for (int i=n; i>=0; --i){
        add(y);
        ans=max(ans,que(t));
        y^=a[i];
        t^=a[i];
    }

    cout<<ans<<"\n";
}

int main()
{
    pre();
    read();
    kill();
    return 0;
}