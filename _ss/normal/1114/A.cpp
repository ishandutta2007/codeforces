#include <iostream>

using namespace std;

int main()
{
    int x,y,z,a,b,c;
    cin>>x>>y>>z>>a>>b>>c;
    a=a-x;
    bool kt=true;
    if (a<0) kt=false;
    if (a<y)
    {
        y=y-a;
        a=0;
    }
    else
    {
        a=a-y;
        y=0;
    }
    if (y>0) b=b-y;
    if (b<0) kt=false;
    if (a+b+c<z) kt=false;
    if (kt) cout<<"YES"; else cout<<"NO";
    return 0;
}