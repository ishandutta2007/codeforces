#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int x,y,a,b;
    cin>>x>>y>>a>>b;
    int n=0;
    vector<int> ansa;
    vector<int> ansb;
    for(int i=a;i<=x;i++)
    for(int j=b;j<=y;j++)
    {
            if(i>j)
            {
                   ansa.push_back(i);
                   ansb.push_back(j);
            }
    }
    cout<<ansa.size()<<endl;
    for(int i=0;i<ansa.size();i++)
    cout<<ansa[i]<<' '<<ansb[i]<<endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}