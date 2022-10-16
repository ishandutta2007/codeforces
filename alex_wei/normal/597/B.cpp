#include<bits/stdc++.h>
using namespace std;
//
struct node{
	int x,y;
}p[500005];
bool cmp(node a,node b){return a.y<b.y;}
int n,s,w;
int main()
{
	cin>>n;
	for(int x=1;x<=n;x++)cin>>p[x].x>>p[x].y;
	sort(p+1,p+n+1,cmp);
	for(int x=1;x<=n;x++)
		if(p[x].x>w)s++,w=p[x].y;
	cout<<s;
	return 0;
}