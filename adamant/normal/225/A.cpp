#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char *argv[])
{
    int n,x;
    
    cin>>n>>x;
    
    int*a=new int[n];
    int*b=new int[n];
    for(int i=0;i<n;i++)
    {
    cin>>a[i]>>b[i];
    }
    int up=x;
    for(int i=1;i<n;i++)
    {
            if(7-a[i]==up || 7-b[i]==up || a[i]==up || b[i]==up)
            {
                          cout<<"NO"<<endl;
                          return 0;
            }
            else
            up=7-up;
            
    }
    cout<<"YES"<<endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}