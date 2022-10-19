#include <cstdlib>
#include <iostream>

#define M 110

using namespace std;


long p[M],n,f[M],d[M];

void init(void){
     for (long i=0; i<M; ++i)
     p[i]=i;
     }
     
long find_set(long x){
     return p[x]==x ? x : p[x]=find_set(p[x]);
     }
     
void union_set(long x, long y){
     x=find_set(x);
     y=find_set(y);
     if (x!=y)
     p[x]=y;
     }

int main()
{
    cin>>n;
    init();
    for (long i=1; i<=n; ++i)
    cin>>f[i];
    for (long i=1; i<=n; ++i)
    cin>>d[i];
    for (long i=1; i<=n; ++i){
        if (i+d[i]<=n)
        union_set(i,d[i]+i);
        if (i-d[i]>=1)
        union_set(i,i-d[i]);
        }
    for (long i=1; i<=n; ++i)
    if (find_set(i)!=find_set(f[i])){
                                     cout<<"NO";
 
                                     return 0;
                                     }
    cout<<"YES";

    return 0;
}