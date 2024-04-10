#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

set<int> s;

void dfs(int n, int fours, int sevens)
{
    if(n>1e10)
        return;
    if(fours==sevens)
        s.insert(n);
    dfs(n*10 + 4, fours+1, sevens);
    dfs(n*10 + 7, fours, sevens+1);
}

int32_t main()
{
    IOS;
    dfs(0, 0, 0);
    int n;
    cin>>n;
    cout<<*s.lower_bound(n);
    return 0;
}