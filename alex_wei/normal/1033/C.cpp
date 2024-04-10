#include<bits/stdc++.h>
using namespace std;
int n,a[100002],pd[100002];
vector <int> d[100002];
void dfs(int x)
{
	int p=0;
	for(int i=0;i<d[x].size();i++){
		if(!pd[d[x][i]])dfs(d[x][i]);
		if(pd[d[x][i]]==2)p=1;
	}
	if(p)pd[x]=1;
	else pd[x]=2;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=i%a[i]==0?a[i]:i%a[i];j<=n;j+=a[i])
			if(i!=j&&a[i]<a[j])
				d[i].push_back(j);
	for(int i=n;i>0;i--)
		if(!d[i].size())
			pd[i]=2;
	for(int i=1;i<=n;i++){
		if(!pd[i])dfs(i);
		cout<<(char)(pd[i]-1+'A');
	}
	return 0;
}