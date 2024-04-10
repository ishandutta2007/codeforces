#include<bits/stdc++.h>
using namespace std;
#define int long long
set<int>r[100010],c[100010];
int n,m,st,ed,up,dn,k,t1,t2,x,y,dir,sum=1;//dir=: 0->right 1->down 2->left 3->up 
signed main(){
	scanf("%lld%lld%lld",&n,&m,&k),st=x=y=1,up=2,ed=m,dn=n;
	for(int i=1;i<=k;i++)scanf("%lld%lld",&t1,&t2),r[t1].insert(t2),c[t2].insert(t1);
	while(true){
		if(dir==0){
			set<int>::iterator it=r[x].upper_bound(y);
			int t;
			if(it==r[x].end())t=ed+1;
			else t=*it;
			t=min(t,ed+1);
			if(t-y==1){
				if(!(x==1&&y==1))break;
			}
			sum+=t-y-1;
			y=t-1;
			ed=y-1;
		}
		if(dir==1){
			set<int>::iterator it=c[y].upper_bound(x);
			int t;
			if(it==c[y].end())t=dn+1;
			else t=*it;
			t=min(t,dn+1);
			if(t-x==1)break;
			sum+=t-x-1;
			x=t-1;
			dn=x-1;
		}
		if(dir==2){
			set<int>::iterator it=r[x].upper_bound(y);
			int t;
			if(it==r[x].begin())t=st-1;
			else it--,t=*it;
			t=max(t,st-1);
			if(y-t==1)break;
			sum+=y-t-1;
			y=t+1;
			st=y+1;
		}
		if(dir==3){
			set<int>::iterator it=c[y].upper_bound(x);
			int t;
			if(it==c[y].begin())t=up-1;
			else it--,t=*it;
			t=max(t,up-1);
			if(x-t==1)break;
			sum+=x-t-1;
			x=t+1;
			up=x+1;
		}
//		printf("%d %d\n",x,y); 
//		printf("%d %d %d %d\n",st,ed,up,dn);
		dir=(dir+1)%4;	
	}
//	printf("%d\n",sum);
	puts(sum==n*m-k?"Yes":"No");
	return 0;
}
/*
3 4 5
1 4
2 1
2 4
3 1
3 4
*/