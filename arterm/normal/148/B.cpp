#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    double vp,vd,t,f,c,d=0,l[200];
    long i=0;
    cin>>vp>>vd>>t>>f>>c;
    l[0]=t*vp;
    if (vd<=vp){
                cout<<0;
                return 0;
                }
    l[0]+=(l[0]/(vd-vp)*vp);
    while (l[i]<c){
          ++i;
          l[i]=l[i-1];
          l[i]+=((l[i]/vd+f)*vp);
          l[i]+=(l[i]/(vd-vp)*vp);
          }
    cout<<i;
    //system("PAUSE");
    return 0;
}