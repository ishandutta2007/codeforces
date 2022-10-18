#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    int y,k,n;
    
    cin>>y>>k>>n;
    int t=k-(y%k);   
    if(t==0)
    t=k;
    if(t+y<=n)
    for(int i=t;i<=n-y;i+=k)
    cout<<i<<' ';
    else cout<<-1;
    cout<<endl;
    
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}