#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b;
}c[100002];
bool cmp(node a,node b){return a.a<b.a;}
int n,p;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>c[i].a>>c[i].b;
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(c[i].b<p)cout<<"Happy Alex",exit(0);
		p=c[i].b;
	}
	cout<<"Poor Alex";
	return 0;
}