#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin>>n;
    int*a=new int[n];
    int*b=new int[n];
    int ax=0;
    int bx=0;
    for(int i=0;i<n;i++)
    {
    cin>>a[i]>>b[i];
    if(a[i])
    ax++;
    if(b[i])
    bx++;
    }
    
    cout<<min(ax,n-ax)+min(bx,n-bx)<<endl;
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}