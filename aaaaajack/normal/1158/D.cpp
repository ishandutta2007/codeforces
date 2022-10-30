#include<bits/stdc++.h>
#define N 2010
using namespace std;
struct point{
	int x,y;
	point(int x=0,int y=0):x(x),y(y){}
	long long operator*(point r)const{return 1LL*x*r.y-1LL*y*r.x;}
	point operator-(point r)const{return point(x-r.x,y-r.y);}
}p[N];
bool del[N];
int get_min(int ori,int n){
	int mn=-1;
	for(int i=0;i<n;i++){
		if(!del[i] && (mn<0 || (p[i]-p[ori])*(p[mn]-p[ori])>0)) mn=i;
	}
	return mn;
}
int get_max(int ori,int n){
	int mx=-1;
	for(int i=0;i<n;i++){
		if(!del[i] && (mx<0 || (p[i]-p[ori])*(p[mx]-p[ori])<0)) mx=i;
	}
	return mx;
}
char s[N];
int main(){
	int n,st=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
		if(p[i].x<p[st].x || p[i].x==p[st].x && p[i].y<p[st].y) st=i;
	}
	scanf("%s",s);
	printf("%d",st+1);
	del[st]=true;
	for(int i=0;i<n-1;i++){
		if(s[i]=='L'){
			st=get_min(st,n);
		}
		else{
			st=get_max(st,n);
		}
		printf(" %d",st+1);
		del[st]=true;
	}
	puts("");
}