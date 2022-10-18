#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int n,m,a;
    
    cin>>n>>m>>a;
    
    long long ans1=m/a;
    
    if(m%a)
    ans1++;
    
    long long ans2=n/a;
    
    if(n%a)
    ans2++;
    
    cout<<ans1*ans2<<endl;
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}