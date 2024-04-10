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
    int n;
    cin>>n;
    string*a=new string[n];
    int ans=0;
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    bool m=false;
    for(int j=0;j<a[i].size();j++)
    if(a[i][j]=='-')
    m=true;
    if(m)
    ans--;
    else
    ans++;
    }
    cout<<ans<<endl;

    return EXIT_SUCCESS;
}