#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

long long tovs[5];

long long tovs1[5]={0,0,0,0,0};

int main(int argc, char *argv[])
{
    long long n;
    
    cin>>n;
    
    long long*bat=new long long[n];
    
    for(long long i=0;i<n;i++)
    {
            cin>>bat[i];
    }
    
    
    for(int i=0;i<5;i++)
    cin>>tovs[i];
    
    long long sum=0;
    int from;
    for(long long i=0;i<n;i++)
    {
            sum+=bat[i];
                         for(int i=4;i>=0;i--)
                         {
                          if(sum>=tovs[i])       
                          {
                              tovs1[i]+=sum/tovs[i]; 
                              sum%=tovs[i]; 
                                          
                          }
                         }
    }
    cout<<tovs1[0];
    for(int i=1;i<5;i++)
    cout<<' '<<tovs1[i];
    cout<<endl<<sum<<endl;
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}