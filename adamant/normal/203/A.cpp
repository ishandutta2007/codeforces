#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    int x,t,a,b,da,db;
    
    cin>>x>>t>>a>>b>>da>>db;

    for(int i=0;i<t;i++)
    for(int j=0;j<t;j++)
    if( ( ( ( (a-da*i) + (b-db*j) ) == x) || ( (a-da*i) == x) ) || ( (b-db*j) == x ) || (0 == x) )
    {
        cout<<"YES"<<endl;
        return 0;
    }
    
    cout<<"NO"<<endl;
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}