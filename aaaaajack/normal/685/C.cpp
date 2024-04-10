#include<bits/stdc++.h>
#define N 100100
using namespace std;
long long mx[4],mn[4],val[4],rv[4],tmx[2],tmn[2],ax,ay,az;
bool fx[2],fn[2];
long long safe_add(long long a,long long b){
	long long r=a/2+b/2;
	if(a>0&&b>0&&(a&1)) r++;
	if(a<0&&b<0&&(a&1)) r--;
	return (a+b)/2;
}
int main(){
	int t,n;
	long long x,y,z;
	long long d;
	unsigned long long gap;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		d=0;
		for(int i=0;i<4;i++){
			mx[i]=-(1LL<<62),mn[i]=1LL<<62;
		}
		for(int i=0;i<n;i++){
			scanf("%I64d%I64d%I64d",&x,&y,&z);
			mx[0]=max(x+y+z,mx[0]);
			mn[0]=min(x+y+z,mn[0]);
			mx[1]=max(x+y-z,mx[1]);
			mn[1]=min(x+y-z,mn[1]);
			mx[2]=max(x-y+z,mx[2]);
			mn[2]=min(x-y+z,mn[2]);
			mx[3]=max(x-y-z,mx[3]);
			mn[3]=min(x-y-z,mn[3]);
		}
		fx[0]=fx[1]=fn[0]=fn[1]=0;
		for(int i=0;i<4;i++){
			d=max(d,(mx[i]-mn[i]+1)/2);
		}
		for(int i=0;i<2;i++){
			tmx[i]=mn[i]+mn[3-i];
			if(tmx[i]&1) tmx[i]--,fx[i]=true;
			tmx[i]/=2;
			tmn[i]=mx[i]+mx[3-i];
			if(tmn[i]&1) tmn[i]++,fn[i]=true;
			tmn[i]/=2;
		}
		for(int i=0;i<2;i++){
			d=max(d,(tmn[i]-tmx[i^1]+1)/2);
		}
		bool u[2]={};
		for(int i=0;i<4;i++){
			if(mn[i]+d==mx[i]-d){
				u[(mn[i]+d)&1]=true;
			}
		}
		for(int i=0;i<2;i++){
			if(tmx[i]+d==tmn[i^1]-d){
				if(!fx[i]) u[(mn[i]+d)&1]=true;
				if(!fn[i^1]) u[(mx[i^1]-d)&1]=true;
			}
		}
		if(u[0]&&u[1]) d++;
		fprintf(stderr,"%I64d\n",d);
		for(int ch=0;ch<2;ch++){
			bool gg=false;
			for(int i=0;i<4;i++){
				val[i]=mx[i]-d;
				if((val[i]&1)!=ch) val[i]++;
				rv[i]=mn[i]+d;
				if((rv[i]&1)!=ch) rv[i]--;
				if(val[i]>rv[i]) gg=true;
			}
			if(gg) continue;
			if(safe_add(val[0],val[3])<safe_add(val[1],val[2])){
				gap=val[1]+val[2]-val[0]-val[3];
				if(gap<rv[0]-val[0]){
					val[0]+=gap;
					break;
				}
				else{
					gap-=rv[0]-val[0];
					val[0]=rv[0];
					val[3]+=gap;
					if(val[3]<=rv[3]) break;
				}
			}
			else{
				gap=val[0]+val[3]-val[1]-val[2];
				if(gap<rv[1]-val[1]){
					val[1]+=gap;
					break;
				}
				else{
					gap-=rv[1]-val[1];
					val[1]=rv[1];
					val[2]+=gap;
					if(val[2]<=rv[2]) break;
				}
			}
		}
		ax=safe_add(val[0],val[3]);
		ay=safe_add(val[0],-val[2]);
		az=safe_add(val[0],-val[1]);
		printf("%I64d %I64d %I64d\n",ax,ay,az);
	}
	return 0;
}