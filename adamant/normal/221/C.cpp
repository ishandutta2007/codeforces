#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
    int tmp;
    cin>>tmp;
    arr.push_back(tmp);
    }
    vector<int> arr2=arr;
    sort(arr2.begin(),arr2.end());
    int no=0;
    for(int i=0;i<n;i++)
    {
            if(arr[i]!=arr2[i])
            {
            no++;
            if(no>2)
            {
                      cout<<"NO"<<endl;
                      return 0;
            }
            }
    }
    
    cout<<"YES"<<endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}