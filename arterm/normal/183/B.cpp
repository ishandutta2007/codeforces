#include <iostream>

#define long long long
#define M 267
#define N 1000100

using namespace std;

long a[N],n,m;

struct po{
    long x,y;
    void read(){
        cin>>x>>y;
    }
} p[M];

bool lie(po a, po b, po c){
    return (b.y-a.y)*(c.x-b.x)==(c.y-b.y)*(b.x-a.x);
}

void read(void){
    cin>>n>>m;
    for (int i=0; i<m; ++i)
    p[i].read();
}

void kill(void){
    for (int i=1; i<=n; ++i)
    a[i]=1;
    for (int i=0; i<m; ++i)
    for (int j=i+1; j<m; ++j){
        long s=2;
        for (int k=j+1; k<m; ++k)
        if (lie(p[i],p[j],p[k]))
        s++;
        if (p[i].y!=p[j].y){
            long x=p[j].x-p[j].y*(p[j].x-p[i].x)/(p[j].y-p[i].y);
            po h={x,0};
            if (1<=x && x<=n && lie(p[i],p[j],h))
            a[x]=max(a[x],s);
        }
    }


    long ans=0;
    for (int i=1; i<=n; ++i)
    ans+=a[i];

    cout<<ans<<"\n";
}

int main()
{
    read();
    kill();
    return 0;
}