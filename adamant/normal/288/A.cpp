#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

#define ll long long
#define ld long double

int main(int argc, char *argv[])
{
    int n,k;
    
    cin>>n>>k;
    
    string ans;
    for(int i=0;i<n;i++)
    ans.push_back(i%2?'b':'a');
    if(k>n || k==1 && n>1)
    {
    cout<<-1<<endl;
    return 0;
    }
    else
    for(int i=0;i<k-2;i++)
    {
            ans[n-i-1]='a'+k-i-1;
    }
    cout<<ans<<endl;
    //system("pause");
    return EXIT_SUCCESS;
}