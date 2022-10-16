#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
}c[8];
bool cmp(node a,node b){return a.x<b.x||a.x==b.x&&a.y<b.y;}
int x,y,a[1000002],b[1000002];
int main()
{
	for(int i=0;i<8;i++)
		cin>>c[i].x>>c[i].y;
	for(int i=0;i<8;i++)
		x+=!a[c[i].x],a[c[i].x]++,y+=!b[c[i].y],b[c[i].y]++;
	sort(c,c+8,cmp);
	if(x==3&&y==3&&c[0].x==c[1].x&&c[1].x==c[2].x&&c[3].x==c[4].x&&c[5].x==c[6].x&&c[6].x==c[7].x&&
	c[0].y==c[3].y&&c[3].y==c[5].y&&c[1].y==c[6].y&&c[2].y==c[4].y&&c[4].y==c[7].y)cout<<"respectable";
	else cout<<"ugly";
	return 0;
}