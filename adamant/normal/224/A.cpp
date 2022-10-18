#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <cstring>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    int a,b,c;
    cin>>a>>b>>c;
    int x=sqrt((a*b)/c), y=sqrt((a*c)/b), z=sqrt((b*c)/a);
    cout<<4*x+4*y+4*z<<endl;
    
    
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}