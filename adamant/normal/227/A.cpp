#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char *argv[])
{
    int x0,y0;
    cin>>x0>>y0;
    int x1,y1;
    cin>>x1>>y1;
    int x2,y2;
    cin>>x2>>y2;
    x1-=x0;
    x2-=x0;
    y1-=y0;
    y2-=y0;
    x0=0;
    y0=0;
    double a=x1-x0,b=y1-y0;
    double c=x2-x0,d=y2-y0;
    
    if(a/b == c/d)
    cout<<"TOWARDS"<<endl;
    else if(y1>0)
    {
    if(x2>x1)
    cout<<"RIGHT"<<endl;
    else
    cout<<"LEFT"<<endl;
    }
    else if(y1==0)
    {
         if(x1>0)
         {
        if(y2>0) 
        cout<<"LEFT"<<endl;
        else
        cout<<"RIGHT"<<endl;
        }
        else
        {
        if(y2>0) 
        cout<<"RIGHT"<<endl;
        else
        cout<<"LEFT"<<endl;
        }
    }
    else
    {
    if(x2>x1)
    cout<<"LEFT"<<endl;
    else
    cout<<"RIGHT"<<endl;
    }
    
    
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}