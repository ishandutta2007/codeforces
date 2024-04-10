#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,s;
void dfs(ll d)
{
	if(d<=n)s++;
	else return;
	dfs(d*10+4),dfs(d*10+7);
}
int main()
{
	cin>>n;
	dfs(0);
	cout<<s-1;
    return 0;
}