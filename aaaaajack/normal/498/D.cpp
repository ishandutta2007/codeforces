#include<cstdio>
#define N 100100
#define M 60
using namespace std;
int seg_tree[N*2][M];
int a[N];
void upd(int x,int n){
	if(x>=2*n) return;
	int b=(x&-x)>>1,l=x-b,r=x+b;
	int i,tmp;
	for(i=0;i<M;i++){
		tmp=seg_tree[l][i];
		seg_tree[x][i]=tmp+(r<2*n?seg_tree[r][(i+tmp)%M]:0);
	}
}
int main(){
	int i,j,k,l,n,q,tmp,x,y;
	char op[5];
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(j=0;j<M;j++){
			if(j%a[i]==0){
				seg_tree[i*2-1][j]=2;
			}
			else seg_tree[i*2-1][j]=1;
		}
	}
	for(i=2;i<n*2;i<<=1){
		for(j=i;j<n*2;j+=(i<<1)){
			upd(j,n);
		}
	}
	scanf("%d",&q);
	while(q--){
		scanf("%s%d%d",op,&x,&y);
		if(op[0]=='A'){
			y=2*y-3;
			x=2*x-1;
			i=0;
			while(x<=y){
				j=x+(x&-x);
				if((j&-j)!=((x&-x)<<1)||j+(j&-j)>y){
					i+=seg_tree[x][i%M];
					x=j+1;
				}
				else x=j;
			}
			printf("%d\n",i);
		}
		else{
			a[x]=y;
			for(i=0;i<M;i++) seg_tree[2*x-1][i]=1+(i%y==0);
			for(i=2*x-1;i<2*n;){
				k=i-(i&-i);
				l=i+(i&-i);
				if((k&-k)==((i&-i)<<1)){
					upd(k,n);
					i=k;
				}
				else{
					upd(l,n);
					i=l;
				}
			}
		}
	}
	return 0;
}