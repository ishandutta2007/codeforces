#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,rat,a;
}c[2002];
bool cmp(node a,node b){return a.rat>b.rat;}
int n,p[2002];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>c[i].rat,c[i].x=i;
	sort(c,c+n,cmp);
	for(int i=0;i<n;i++)
		c[i].a=(i==0||c[i].rat!=c[i-1].rat?i+1:c[i-1].a),p[c[i].x]=c[i].a;
	for(int i=0;i<n;i++)
		cout<<p[i]<<" "; 
	return 0;
}