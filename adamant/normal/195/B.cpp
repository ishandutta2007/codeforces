#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <numeric>

#define u64 long long

using namespace std;

int main(int argc, char *argv[])
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int n,m;
    
    cin>>n>>m;
    
    int sr=m/2+1;
    
    bool f=true;
    int x,y;
    for(int i=0;i<n;i++)
    {
          int k=i%m+1;  
          if(k==1)
          {
          x=1;
          y=0;
          }
          f=(k%2);
          //cout<<endl<<x<<endl<<endl;
    if(!(m%2))
    {
           if(f)
           {
    cout<<sr-k+y<<endl;
           }
           else
           {
    cout<<sr+k-2-y<<endl;
    y++;
           }
    }
    else
    {
    if(f)
           {
    cout<<sr+k-x<<endl;
           }
           else
           {
    cout<<sr-k+x<<endl;
    x++;
           }
    }
    
    }
    
    //system("PAUSE");
    
    
    
    return EXIT_SUCCESS;
}