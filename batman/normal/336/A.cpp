#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    int x,y,x1,x2,y1,y2;
    cin>>x>>y;
    x1=0;
    y2=0;
    if(y>0)
        y1=y+abs(x);
    else
        y1=y+(-1)*abs(x);
    if(x>0)
        x2=x+abs(y);
    else
        x2=x+(-1)*abs(y);
    if(x2>0)
        cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2;
    else
        cout<<x2<<" "<<y2<<" "<<x1<<" "<<y1;                
    return 0;
}