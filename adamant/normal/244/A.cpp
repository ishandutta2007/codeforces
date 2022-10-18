#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char *argv[])
{
    int n,k;
    cin>>n>>k;
    int*a=new int[k];
    int*an=new int[n*k];
    for(int i=0;i<n*k;i++)
    an[i]=0;
    for(int i=0;i<k;i++)
    {
    cin>>a[i];
    an[a[i]-1]=1;
    }
    
    int x=0;
    
    for(int i=0;i<k;i++)
    {
            cout<<a[i]<<' ';
            int o=1;
            for(int j=0;o!=n && j<n*k;j++)
            {
                    if(!(an[j]))
                    {
                                an[j]=i+1;
                                o++;
                                cout<<j+1<<' ';
                    }
            }
            cout<<endl;
    }        
    
    
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}