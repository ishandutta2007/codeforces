#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    int s,n;
    cin>>s>>n;
    int*x=new int[n];
    int*y=new int[n];
    for(int i=0;i<n;i++)
    cin>>x[i]>>y[i];
    
    bool again;
    do
    {
         again=false;
    for(int i=1;i<n;i++)
    {
            if(x[i]>x[i-1])
            {
                           again=true;
                           int tmp=x[i];
                           int tmp1=y[i];
                           x[i]=x[i-1];
                           y[i]=y[i-1];
                           x[i-1]=tmp;
                           y[i-1]=tmp1;
            }
    }
    }
    while(again);
    
    for(int i=n-1;i>=0;i--)
    {
            if(s>x[i])
            {
                      s+=y[i];
            }
            else
            {
                cout<<"NO"<<endl;
                return 0;
            }
    }
    cout<<"YES"<<endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}