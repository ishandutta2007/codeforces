#include<bits/stdc++.h>
using namespace std;
struct node{
	int d,val;
}c[100005];
bool cmp(node a,node b){return a.val<b.val;}
int n,k[100005];
vector <int> ans[100005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>c[i].val,c[i].d=i;
	sort(c+1,c+n+1,cmp);
	for(int i=n;i>0;i--)
		k[i]=max(k[i+1],c[i].d),ans[k[i]].push_back(i);
	for(int i=1;i<=n;i++){
		for(int j=0;j<ans[i].size();j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}