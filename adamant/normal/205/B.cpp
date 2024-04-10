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
    
    vector <int> a;
    int t;
    
    cin>>t;
    a.push_back(t);
    
    long long ans=0;
    int check;
    vector< vector<int> > podp;
    vector<int> temp;
    temp.push_back(a[0]);  
    
    for(int i=1;i<n;i++)
    {
    cin>>t;
    a.push_back(t);        
            if(a[i-1]>=a[i])
            {
                           temp.push_back(a[i]);
            }
            else
            {
            podp.push_back(temp);
            temp.clear();
            temp.push_back(a[i]);
            }
            
    }
    podp.push_back(temp);
    //cout<<podp.size()<<endl;
    for(int i=0;i<podp.size();i++)
    ans+=podp[i][0]-podp[i][podp[i].size()-1];
    
    cout<<ans<<endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}