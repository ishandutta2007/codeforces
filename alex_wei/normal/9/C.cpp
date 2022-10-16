#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,s;
void dfs(ll f)
{
	if(f>n)return;
	s++;
	dfs(f*10+1);
	dfs(f*10);
}
int main()
{
	cin>>n;
	dfs(1);
	cout<<s;
	return 0;
}