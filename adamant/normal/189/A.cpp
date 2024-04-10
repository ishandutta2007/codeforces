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
    int n,a[3];
    cin>>n>>a[0]>>a[1]>>a[2];
    
    int ans=0;
    
    sort(a,a+3);
    
    for(int i=0;i<=n/a[0];i++)
    for(int j=0;j<=n/a[1];j++)
    {
            int k=(n-a[0]*i-a[1]*j);
            if(k%a[2])
            continue;
            if(k<0)
            break;
            if(i+j+k/a[2]>ans)
            ans=i+j+k/a[2];
    }
    cout<<ans<<endl;
    return EXIT_SUCCESS;
}