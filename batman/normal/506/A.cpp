#include <iostream>
#include <vector>
using namespace std;
#define N 33000
int n,l,DP[N][501],gems[N],maxgem;
bool mark[N][501];
int dp(int p,int d)
{
    if(p>maxgem || d==0)
        return 0;
    if(mark[p][d]==true)
        return DP[p][d];
    DP[p][d]=gems[p]+max(dp(p+d-1,d-1),max(dp(p+d,d),dp(p+d+1,d+1)));
    mark[p][d]=true;
    return DP[p][d];
            
}

int main()
{
    cin>>n>>l;
    for(int i=0;i<n;i++)
    {
        int gem;
        cin>>gem;
        if(gem>maxgem)
            maxgem=gem;
        gems[gem]++;
    }   
    cout<<dp(l,l);
    return 0;
}