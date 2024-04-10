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
    
    int*a=new int[n];
    vector<int> ans;
    ans.push_back(0);
    int x=0;
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    if(a[i]<0)
    x++;
    if(x==3)
    {
            x=1;
            ans.push_back(1);
    }
    else
    ans[ans.size()-1]++;
    }
    
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<' ';
    cout<<endl;
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}