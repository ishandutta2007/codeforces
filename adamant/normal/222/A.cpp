#include <cstdlib>
#include <iostream>
#include <math.h>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>


using namespace std;
int k;
bool check(vector<int> a)
{
     //cout<<count(a.begin()+k-1,a.end(),a[k-1])<<endl;
     if(count(a.begin()+k-1,a.end(),a[k-1])==a.size()-k+1)
     return 0;
     else
     return 1;
}


int main(int argc, char *argv[])
{
    int n;
    cin>>n>>k;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
    int tmp;
    cin>>tmp;
    a.push_back(tmp);
    }
    int ans=k;
    for(int i=k-1;i>=0;i--)
    if(a[i]==a[k-1])
    ans--;
    else
    break;
    if(!check(a))
    cout<<ans<<endl;
    else
    cout<<-1<<endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}