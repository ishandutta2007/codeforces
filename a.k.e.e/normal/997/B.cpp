#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

int n,c[55]={0,7,8,9,5,6,7,8,9,5,6,7,8,4,5,6,7,8,4,5,6,7
,3,4,5,6,8,3,4,5,12,2,3,4,11,7,2,3,10,11,1,2,9,10,6,1,8,9,10};

int main()
{
    scanf("%d",&n);
    long long ans=0;
    for(int i=0;i<49;i++)
    	if(n>=c[i])ans+=n-c[i]+1;
    cout<<ans<<endl;
    return 0;
}