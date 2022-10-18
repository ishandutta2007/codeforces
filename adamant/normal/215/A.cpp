#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    
    cin>>n;
    
    int*a=new int[n];
    
    for(int i=0;i<n;i++)    
    cin>>a[i];
    
    int m;
    
    cin>>m;
    
    int*b=new int[m];
    
    for(int i=0;i<m;i++)    
    cin>>b[i];
    
    int max=0;
    
    int count=0;
    
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    if( !(b[j]%a[i]) )
    {
        if(b[j]/a[i] > max)
        {
        count=1;
        max=b[j]/a[i];             
        }
        else if(b[j]/a[i] == max)
        count++;
    }
    
    cout<<count<<endl;
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}