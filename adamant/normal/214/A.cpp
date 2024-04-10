#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int n,m;
    
    cin>>n>>m;
    
    int sum=0;
    
    for(int i=0;i<=1000;i++)
    for(int j=0;j<=1000;j++)
    {
            if( ( (i*i+j) ==n) && ( (i+j*j) ==m) )
            sum++;
            
    }
    
    cout<<sum<<endl;
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}