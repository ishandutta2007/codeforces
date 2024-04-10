#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin>>n;
    
    int*a=new int[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
            cin>>a[i];
            sum+=a[i];
    }
    if(sum%n)
    cout<<n-1<<endl;
    else
    cout<<n<<endl;
    
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}