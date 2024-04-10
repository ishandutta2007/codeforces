#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

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
    
    for(int i=0;i<n;i++)
    {
            if(i<m-1 && n-i<m)
            a[i]=(a[i]+accumulate(&b[m-(n-i)],&b[0+i+1],0));
            else if(i<m-1)
            a[i]=(a[i]+accumulate(&b[0],&b[0+i+1],0));
            else if(n-i<m)
            a[i]=(a[i]+accumulate(&b[m-(n-i)],&b[m],0));
            else
            a[i]=(a[i]+accumulate(&b[0],&b[m],0));
            //cout<<a[i]<<endl;
    }
     
     for(int i=0;i<n;i++)
     cout<<a[i]%c<<' ';
    cout<<endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}