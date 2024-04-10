#include<bits/stdc++.h>
using namespace std;
const int BBB=1000;
int n;
struct node{
	int x,y,id;
	friend bool operator<(const node&u,const node&v){
		if(u.x/BBB!=v.x/BBB)return u.x<v.x;
		return (u.x/BBB)&1?u.y<v.y:u.y>v.y;
	}
}p[1001000];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&p[i].x,&p[i].y),p[i].id=i;
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++)printf("%d ",p[i].id);
	return 0;
}