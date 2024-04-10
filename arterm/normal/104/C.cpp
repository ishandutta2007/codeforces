#include <cstdlib>
#include <iostream>

using namespace std;

#define M 200

long n,m,p[M];

void init(void){
     for (long i=0; i<M; ++i)
     p[i]=i;
     }
     
long find(long x){
     return p[x]==x ? x:p[x]=find(p[x]);
     }
     
long uni(long x, long y){
     p[find(y)]=find(x);
     } 

void read(void){
     long a,b;
     cin>>n>>m;
     for (long i=0; i<m; ++i){
         cin>>a>>b;
         uni(a,b);
         }
     }

bool ans(void){
     for (long i=1; i<n; ++i)
     if (find(i)!=find(i+1))
     return 0;
     if (m!=n)
     return 0;
     return 1;
     }

int main()
{
    init();
    read();
    if (ans())
    cout<<"FHTAGN!";
    else
    cout<<"NO";
    //system("PAUSE");
    return 0;
}