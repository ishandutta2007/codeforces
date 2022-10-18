#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char *argv[])
{
    int n,m;
    
    cin>>n>>m;
    
    int*a=new int[m];
    int*b=new int[m];
    for(int i=0;i<m;i++)
    {
    cin>>a[i];
    b[i]=a[i];
    }
    
    int max=0,min=0;
    
    for(int i=0;i<n;i++)
    {
            max+=*max_element(a, a+m);
            *max_element(a, a+m)-=1;
    }
    
    for(int i=0;i<n;i++)
    {
            min+=*min_element(b, b+m);
            *min_element(b, b+m)-=1;
            if(*min_element(b, b+m)==0)
            *min_element(b, b+m)=2000000000;
    }
    
    cout<<max<<' '<<min<<endl;
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}