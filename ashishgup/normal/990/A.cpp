#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
    IOS;
    int n, m, a, b;
    cin>>n>>m>>a>>b;
    int rem=n%m;
    int cost1=b*rem;
    int cost2=(m-rem)*a;
    cout<<min(cost1, cost2);
    return 0;
}