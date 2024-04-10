#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int n,m,c;
    
    cin>>n>>m>>c;
    
    int*a=new int[n];
    int*b=new int[m];
    
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    for(int i=0;i<m;i++)
    cin>>b[i];
    
    for(int i=0;i<n-m+1;i++)
     for(int j=0;j<m;j++)       
     a[i+j]=(a[i+j]+b[j])%c;
     
     for(int i=0;i<n;i++)
     cout<<a[i]<<' ';
    cout<<endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}