#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char *argv[])
{
    int n,k;
    cin>>n>>k;
    
    int*r=new int[2*n+1];
    
    for(int i=0;i<2*n+1;i++)
    cin>>r[i];
    int ch=0,i=1;
    
    while(ch<k)
    {
               if(r[i]-r[i-1]>1 && r[i]-r[i+1]>1)
               {
             ch++;  
           r[i]--;
           }
           i+=2;         
    }
    cout<<r[0];
    for(int i=1;i<2*n+1;i++)
    cout<<' '<<r[i];
    cout<<endl;
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}