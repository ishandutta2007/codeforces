#include<bits/stdc++.h>
#define N 200100
using namespace std;
int f[3][N];
char a[N];
set<int> in[3];
int sum(int s,int x){
	int r=0;
	while(x){
		r+=f[s][x];
		x-=x&-x;
	}
	return r;
}
void upd(int s,int x,int v){
	while(x<N){
		f[s][x]+=v;
		x+=x&-x;
	}
}
int solve(int n){
	int l[3],r[3],ans=0;
	//left of 0: [l[1],n] or [1,min(l[1],l[2])-1]
	//right of 0:  [1,r[1]] or [max(r[1],r[2])+1,n]
	for(int j=0;j<3;j++){
		if(in[j].empty()){
			l[j]=n+1;
			r[j]=0;
		}
		else{
			l[j]=*(in[j].begin());
			r[j]=*(in[j].rbegin());
		}
	}
	for(int j=0;j<3;j++){
		int l1=min(l[(j+1)%3],l[(j+2)%3])-1,l2=r[(j+1)%3];
		int r1=l[(j+1)%3],r2=max(r[(j+1)%3],r[(j+2)%3])+1;
		ans+=sum(j,min(l1,l2));
		ans+=sum(j,n)-sum(j,max(r1,r2)-1);
		if(l1>=r2) ans+=sum(j,l1)-sum(j,r2-1);
		if(l2>=r1) ans+=sum(j,l2)-sum(j,r1-1);
	}
	return ans;
}
int main(){
	char c[10]="RSP";
	int n,q;
	scanf("%d%d",&n,&q);
	scanf("%s",a+1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			if(a[i]==c[j]){
				in[j].insert(i);
				upd(j,i,1);
			}
		}
	}
	printf("%d\n",solve(n));
	while(q--){
		int x;
		char tmp;
		scanf("%d %c",&x,&tmp);
		for(int j=0;j<3;j++){
			if(a[x]==c[j]){
				in[j].erase(x);
				upd(j,x,-1);
			}
		}
		for(int j=0;j<3;j++){
			if(tmp==c[j]){
				in[j].insert(x);
				upd(j,x,1);
			}
		}
		a[x]=tmp;
		printf("%d\n",solve(n));
	}
}