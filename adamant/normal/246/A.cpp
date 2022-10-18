#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin>>n;
    
    if(n<=2)
    cout<<-1;
    else
    for(int i=n;i>=1;i--)
    cout<<i<<' ';
    cout<<endl;
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}