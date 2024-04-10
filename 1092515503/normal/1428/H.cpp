#include<bits/stdc++.h>
using namespace std;
int n,m;
int q[410];
int qry(int x,int y){printf("? %d %d\n",x,y),fflush(stdout),scanf("%d",&x);return x;}
void asw(int*a){putchar('!');for(int i=0;i+1<n;i++)printf(" %d",a[i]);puts(""),fflush(stdout);}
void solve(int _n,int _m,int _k){
	static int p[410];
	n=_n,m=_m;
	int val=qry(0,1),lav;
	vector<int>v;
	bool cns=false;
	for(int i=1;i<n;i++)v.push_back(i);
	for(p[0]=1;!v.empty();){
		lav=qry(0,1),p[0]++,swap(lav,val);
//		printf("STATE SET:%d\n",p[0]); 
		if(val>lav)cns=true;
		else if(cns){
//			puts("JUDGE START.");
			val=qry(0,-1),p[0]--,cns=false;
			do{
				int l=0,r=v.size()-1;
				bool sd=false;
				while(l<r){
					int mid=(l+r)>>1;
					if(!sd)for(int i=l;i<=mid;i++)val=qry(v[i],-1);
					else for(int i=mid+1;i<=r;i++)val=qry(v[i],1);
					lav=qry(0,-1),swap(lav,val);
					if(lav>val)sd=false,l=mid+1;else sd=true,r=mid;
					val=qry(0,1);
				}
//				printf("JUDGE DONE:%d(%d)\n",v[l],sd);
				p[v[l]]=p[0]-m-1;
				for(int i=0;i<=m-sd;i++)qry(v[l],-1);
				v.erase(v.begin()+l);
				lav=qry(0,-1),val=qry(0,1);
				if(val<=lav)break;
				lav=qry(0,1),swap(lav,val);
				if(val>lav){val=qry(0,-1);break;}
				val=qry(0,-1);
			}while(!v.empty());
			lav=qry(0,1),swap(lav,val),p[0]++;
			if(val>lav)cns=true;
		}
	}
//	for(int i=0;i<n;i++)printf("%d ",p[i]);puts("");
	for(int i=1;i<n;i++)p[i]=(p[i]-p[0]%(n*m)+2*n*m)%(n*m);
	asw(p+1);
}
int main(){
	int _n,_m;
	scanf("%d%d",&_n,&_m);
	solve(_n,_m,0);
	return 0;
}