#include <cstdlib>
#include <iostream>

#define M 200
#define C 50000

using namespace std;

int main()
{
    long a,b,n,x[M],u=0;
    cin>>n>>a>>b;
    x[0]=1;
    if (b==1)
    x[0]=2;
    for (long i=0; i<b; ++i){
        x[u+1]=2*x[u];
        u++;
        }
    if (b==0){
              x[0]=4;
              x[1]=4;
              ++u;
              }
    for (long i=0; i<a; ++i){
        x[u+1]=x[u]+1;
        ++u;
        }
    if (u>=n && n>1){
            cout<<-1;
            return 0;
            }
    while (u<n)
    x[++u]=1;
    for (long i=0; i<n; ++i)
    cout<<x[i]<<" ";
    //system("PAUSE");
    return 0;
}