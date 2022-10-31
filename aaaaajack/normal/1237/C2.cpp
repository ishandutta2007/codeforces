#include<bits/stdc++.h>
#define N 300100
using namespace std;
struct point{
	int x,y,z;
	int id;
	bool operator<(const point &rhs)const{
		return x<rhs.x || x==rhs.x&&y<rhs.y || x==rhs.x&&y==rhs.y &&z<rhs.z;
	}
}p[N];
bool del[N];
int shrink(int n){
	int m=0;
	for(int i=0;i<n;i++){
		if(!del[i]) p[m++]=p[i];
		else del[i]=false;
	}
	return m;
}
int main(){
	int n,x,y;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
		p[i].id=i+1;
	}
	sort(p,p+n);
	int pre=-1;
	for(int i=0;i<n;i++){
		if(i && (p[i].x>p[i-1].x || p[i].y>p[i-1].y)){
			pre=-1;
		}
		if(pre>=0){
			printf("%d %d\n",p[pre].id,p[i].id);
			del[pre]=del[i]=true;
			pre=-1;
		}
		else{
			pre=i;
		}
	}
	n=shrink(n);
	pre=-1;
	for(int i=0;i<n;i++){
		if(i && p[i].x>p[i-1].x){
			pre=-1;
		}
		if(pre>=0){
			printf("%d %d\n",p[pre].id,p[i].id);
			del[pre]=del[i]=true;
			pre=-1;
		}
		else{
			pre=i;
		}
	}
	n=shrink(n);
	pre=-1;
	for(int i=0;i<n;i++){
		if(pre>=0){
			printf("%d %d\n",p[pre].id,p[i].id);
			del[pre]=del[i]=true;
			pre=-1;
		}
		else{
			pre=i;
		}
	}
	return 0;
}