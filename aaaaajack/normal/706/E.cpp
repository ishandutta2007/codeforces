#include<bits/stdc++.h>
#define N 1010
using namespace std;
struct node{
	node *nx;
	node *ny;
	int val;
}a[N][N];
int main(){
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j].val);
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i<n) a[i][j].nx=&a[i+1][j];
			if(j<m) a[i][j].ny=&a[i][j+1];
		}
	}
	while(q--){
		int i[2],j[2],h,w;
		scanf("%d%d%d%d%d%d",&i[0],&j[0],&i[1],&j[1],&h,&w);
		node *st[2],*ed[2];
		for(int b=0;b<2;b++){
			i[b]--;
			j[b]--;
			st[b]=&a[0][0];
			for(int t=0;t<i[b];t++){
				st[b]=st[b]->nx;
			}
			for(int t=0;t<j[b];t++){
				st[b]=st[b]->ny;
			}
			ed[b]=st[b];
		}
		for(int t=0;t<h;t++){
			for(int b=0;b<2;b++){
				ed[b]=ed[b]->nx;
			}
			swap(ed[0]->ny,ed[1]->ny);
		}
		for(int t=0;t<w;t++){
			for(int b=0;b<2;b++){
				st[b]=st[b]->ny;
				ed[b]=ed[b]->ny;
			}
			swap(st[0]->nx,st[1]->nx);
			swap(ed[0]->nx,ed[1]->nx);
		}
		for(int t=0;t<h;t++){
			for(int b=0;b<2;b++){
				st[b]=st[b]->nx;
			}
			swap(st[0]->ny,st[1]->ny);
		}
	}
	for(int i=1;i<=n;i++){
		node *cur=&a[i][0];
		for(int j=1;j<=m;j++){
			cur=cur->ny;
			printf("%d%c",cur->val,j<m?' ':'\n');
		}
	}	
	return 0;
}