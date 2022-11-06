//#include "bits/stdc++.h"
#include <cstdio>
#include <cstring>
#include <cassert>
#include <utility>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b ; ++i)

int p[200005];
int find(int a){
	return p[a]<0?a:p[a]=find(p[a]);
}
void uni(int a,int b){
	a=find(a);b=find(b);
	if(a==b)return;
	if(p[a]>p[b])swap(a,b);
	if(p[a]==p[b])--p[a];
	p[b]=a;
}

int f[200005];
int get(int p){
	int ans=0;
	while(p){
		ans+=f[p];
		p-=(p&-p);
	}
	return ans;	
}
void upd(int p,int val){
	while(p<=200003){
		f[p]+=val;
		p+=(p&-p);
	}		
}

int main(){
	memset(p,-1,sizeof(p));
	memset(f,0,sizeof(f));
	rep(i,1,(int)2e5+3)
		upd(i,1);
	int n,q;
	scanf("%d%d",&n,&q);
	rep(i,0,q){
		int type,x,y;
		scanf("%d%d%d",&type,&x,&y);
		if(type == 1){
			uni(x,y);
		} else if(type==2){
			int a = 0, b = x;
			while(a != b-1){
				int m = (a+b)/2;
				if(get(m+1) > x)b=m;
				else a = m;
			}
			x = b;
			int yy=get(y+1);
			while(get(x+1)<=y){
				//printf("%d\n",x);
				int t = get(x+1);
				uni(x,t);
				upd(x+1,yy-t);
				upd(t+1,t-yy);
				x=t;
			}
			//printf("f\n");
			//rep(i,0,9)
			//	printf("%d%c",get(i+1)," \n"[i==8]);
		}else{
			printf(find(x)==find(y)?"YES\n":"NO\n");
		}
	}
}