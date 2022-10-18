#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin>>n;
    if(n%2)
    cout<<"-1"<<endl;
    
    else
    {
        cout<<2<<' '<<1;
        
        for(int i=3;i<=n;i+=2)
        cout<<' '<<i+1<<' '<<i;
        cout<<endl;
    }
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}