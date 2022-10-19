#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

long a[3][3];
long r1,r2,d1,d2,c1,c2;

bool dist(void){
     if (a[1][1]!=a[1][2])
     if (a[1][1]!=a[2][2])
     if (a[1][1]!=a[2][1])
     if (a[1][2]!=a[2][2])
     if (a[1][2]!=a[2][1])
     if (a[2][1]!=a[2][2])
     return 1;
     return 0;
     }
     
bool gran(void){
     for (long i=1; i<3; ++i)
     for (long j=1; j<3; ++j)
     if (a[i][j]>9 || a[i][j]<1)
     return 0;
     return 1;
     }

bool rep(long x){
     a[1][1]=x;
     a[1][2]=r1-x;
     a[2][1]=c1-x;
     a[2][2]=d1-x;
     if (a[1][2]+a[2][1]==d2)
     if (a[2][1]+a[2][2]==r2)
     if (a[1][2]+a[2][2]==c2)
     if (dist() && gran()){
                              cout<<a[1][1]<<" "<<a[1][2]<<endl;
                              cout<<a[2][1]<<" "<<a[2][2]<<endl;
                              return 1;
                              }
     return 0;
     }


int main()
{
    cin>>r1>>r2>>c1>>c2>>d1>>d2;
    long s=r1+r2;
    if (s!=d1+d2 || s!=c1+c2){
                 cout<<-1;
                 return 0;
                 }
    
    if (!rep((r1+d1-c2)/2)){
                 cout<<-1;
                 return 0;
                 }
    return 0;
}