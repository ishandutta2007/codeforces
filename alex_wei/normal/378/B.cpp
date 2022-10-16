#include<bits/stdc++.h>
using namespace std;
struct node{int val,id;}a[200005];
bool cmp(node a,node b){return a.val<b.val;}
int n,c,d;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].val>>a[i+n].val,a[i].id=i,a[i+n].id=i+n;
	sort(a+1,a+n+n+1,cmp);
	for(int i=1;i<=n;i++)
		a[i].id>n?d++:c++;
	for(int i=1;i<=n;i++)
		cout<<(i*2<=n||i<=c?1:0);
	cout<<endl;
	for(int i=1;i<=n;i++)
		cout<<(i*2<=n||i<=d?1:0);
	return 0;
}