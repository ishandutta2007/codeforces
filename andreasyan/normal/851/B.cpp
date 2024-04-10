#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

long long x1,x2,x3,y1,y2,y3;
long long her(long long x11,long long y11,long long x21,long long y21)
{
    return (x11-x21)*(x11-x21)+(y11-y21)*(y11-y21);
}
bool cek()
{
    if((x3-x1)*(y2-y1)==(y3-y1)*(x2-x1))
        return false;
    if(her(x1,y1,x2,y2)!=her(x2,y2,x3,y3))
        return false;
    return true;
}
int main()
{
   cin>>x1>>y1>>x2>>y2>>x3>>y3;
    if(cek())
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
   return 0;
}