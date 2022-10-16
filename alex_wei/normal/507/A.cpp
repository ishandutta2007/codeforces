#include<bits/stdc++.h>
using namespace std;
struct node{
	int val,id;
}c[105];
bool cmp(node a,node b){return a.val<b.val;}
int n,k,p;
int main()
{
	cin>>n>>k,p=n+1;
	for(int i=1;i<=n;i++)
		cin>>c[i].val,c[i].id=i;
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++){
		k-=c[i].val;
		if(k<0){p=i;break;}
	}
	cout<<p-1<<endl;
	for(int i=1;i<p;i++)
		cout<<c[i].id<<" ";
	return 0;
}