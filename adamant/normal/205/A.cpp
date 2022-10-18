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
    
    vector<int> inp;
    int t;
    for(int i=0;i<n;i++)
    {
    cin>>t;
    inp.push_back(t);
    }
    
    vector<int>::iterator min=min_element(inp.begin(),inp.end());
    int val=0;
    int mini=*min;
    for(int i=min-inp.begin()+1;i<n;i++)
    {
            if(inp[i]==mini)
            {
                            cout<<"Still Rozdil"<<endl;
                            return 0;
            }
    }
    
    cout<<min-inp.begin()+1<<endl;
    
    
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}