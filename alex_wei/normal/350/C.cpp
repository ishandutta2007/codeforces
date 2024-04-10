#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
}c[100002];
bool cmp(node a,node b){
return abs(a.x)+abs(a.y)<abs(b.x)+abs(b.y)||abs(a.x)+abs(a.y)==abs(b.x)+abs(b.y)&&abs(a.x)<abs(b.x);}
int n,s; 
int main()
{
	cin>>n,s=2*n;
	for(int i=0;i<n;i++){
		cin>>c[i].x>>c[i].y;
		s+=2*(abs(c[i].x)>0)+2*(abs(c[i].y)>0);
	}
	sort(c,c+n,cmp);
	cout<<s<<endl;
	for(int i=0;i<n;i++){
		if(c[i].x>0)cout<<"1 "<<abs(c[i].x)<<" R\n";
		if(c[i].x<0)cout<<"1 "<<abs(c[i].x)<<" L\n";
		if(c[i].y>0)cout<<"1 "<<abs(c[i].y)<<" U\n";
		if(c[i].y<0)cout<<"1 "<<abs(c[i].y)<<" D\n";
		puts("2");
		c[i].x=-c[i].x,c[i].y=-c[i].y;
		if(c[i].x>0)cout<<"1 "<<abs(c[i].x)<<" R\n";
		if(c[i].x<0)cout<<"1 "<<abs(c[i].x)<<" L\n";
		if(c[i].y>0)cout<<"1 "<<abs(c[i].y)<<" U\n";
		if(c[i].y<0)cout<<"1 "<<abs(c[i].y)<<" D\n";
		puts("3");
	}
    return 0;
}