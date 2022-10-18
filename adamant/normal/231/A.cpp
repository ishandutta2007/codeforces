#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin>>n;
    int *a=new int[n],*b=new int[n],*c=new int[n];
    int ans=0;
    for(int i=0;i<n;i++)
    {
            int ba=0;
    int tmp;
    cin>>tmp;
    if(tmp)
    ba++;
    cin>>tmp;
    if(tmp)
    ba++;
    cin>>tmp;
    if(tmp)
    ba++;
    if(ba>=2)
    ans++;
    
    }
    
    cout<<ans<<endl;
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}