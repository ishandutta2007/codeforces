#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    int x,y,z;
    
    int x1,y1,z1;
    
    int a1,a2,a3,a4,a5,a6;
    
    cin>>x>>y>>z>>x1>>y1>>z1>>a1>>a2>>a3>>a4>>a5>>a6;
    
    int sum=0;
    
    if(y>y1)
    {
            sum+=a2;
    }
    else if(y<0)
    {
         sum+=a1;
    }
    
    if(z>z1)
    {
            sum+=a4;
    }
    else if(z<0)
    {
         sum+=a3;
    }
    
    if(x>x1)
    {
            sum+=a6;
    }
    else if(x<0)
    {
         sum+=a5;
    }
    
    cout<<sum<<endl;
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}