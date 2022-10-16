#include<bits/stdc++.h>
using namespace std;
struct node{
	int w,h,g;
}c[200002];
bool cmp(node a,node b){return a.h<b.h;}
int n,s,p[200002];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>c[i].w>>c[i].h,c[i].g=i,s+=c[i].w;
	sort(c,c+n,cmp);
	for(int i=0;i<n;i++)
		p[c[i].g]=(s-c[i].w)*(i==n-1?c[i-1].h:c[n-1].h);
	for(int i=0;i<n;i++)
		cout<<p[i]<<" ";
	return 0;
}