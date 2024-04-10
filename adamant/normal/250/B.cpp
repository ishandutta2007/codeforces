#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin>>n;
    
    string*a=new string[n];
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    int dobs=bool(a[i][a[i].size()-1]!=':');
    bool yep=false;
    for(int j=0;j<a[i].size()-1;j++)
    {
    if(j!=0 && a[i][j-1]!=':' && a[i][j]==':')
    dobs++;
    if(a[i][j]==':' && a[i][j+1]==':')
    {
    yep=true;
    }
    }
    if(yep)
    for(int j=0;j<a[i].size()-1;j++)
    if(a[i][j]==':' && a[i][j+1]==':')
    {
                    a[i].insert(a[i].begin()+j+1,4,'0');
                    for(int k=0;k<7-dobs;k++)
                    {
                            a[i].insert(a[i].begin()+j+1,1,':');
                            a[i].insert(a[i].begin()+j+1,4,'0');
                    }
                    if(a[i][0]==':')
                    a[i].erase(a[i].begin());
                    if(a[i][a[i].size()-1]==':')
                    a[i].erase(a[i].end()-1);

    }
    for(int j=0;j<=a[i].size();j+=5)
    {
            if(a[i][j]==':' || j==a[i].size())
            {
                            a[i].insert(a[i].begin()+j,4,'0');
            }
            else if(a[i][j+1]==':' || j==a[i].size()-1)
            {
                            a[i].insert(a[i].begin()+j,3,'0');
            }
            else if(a[i][j+2]==':' || j==a[i].size()-2)
            {
                            a[i].insert(a[i].begin()+j,2,'0');
            }
            else if(a[i][j+3]==':' || j==a[i].size()-3)
            {
                            a[i].insert(a[i].begin()+j,1,'0');
            }
    }
    cout<<a[i]<<endl;
    }
    
    
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}