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
    if(n<3)
    cout<<-1<<endl;
    else
    if(n==3)
    cout<<210<<endl;
    else
    {
            cout<<1;
            if((n-3)%6==1 || (n-3)%6==2 || (n-3)%6==4)
            for(int i=0;i<n-3;i++)
            cout<<0;
            else
            for(int i=0;i<n-4;i++)
            cout<<0;
            if((n-3)%6==1)
            cout<<50<<endl;
            else if((n-3)%6==2)
            cout<<80<<endl;
            else if((n-3)%6==3)
            cout<<170<<endl;
            else if((n-3)%6==4)
            cout<<20<<endl;
            else if((n-3)%6==5)
            cout<<200<<endl;
            else if((n-3)%6==0)
            cout<<110<<endl;
    }
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}