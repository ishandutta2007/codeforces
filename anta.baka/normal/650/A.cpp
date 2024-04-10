#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    map<int, int> cntx, cnty;
    map<pii, int> pt;
    for(int i=0,x,y; i<n; i++) { cin>>x>>y; cntx[x]++; cnty[y]++; pt[{x,y}]++; }
    unsigned long long ans=0, p;
    for(pii cnt : cntx) { p=cnt.ss; ans+=p*(p-1)/2; }
    for(pii cnt : cnty) { p=cnt.ss; ans+=p*(p-1)/2; }
    for(auto cnt : pt)  { p=cnt.ss; ans-=p*(p-1)/2; }
    cout<<ans;
    return 0;
}