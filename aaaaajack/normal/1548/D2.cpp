#include<bits/stdc++.h>
#define N 6010
using namespace std;
int x[N],y[N];
int in[N];
vector<int> v[4];
int gcd(int a,int b){
	a=abs(a),b=abs(b);
	if(a==0 && b==0) return 0;
	while(b){
		a%=b;
		swap(a,b);
	}
	return a;
}
inline int getg(int i,int j){
	return gcd(x[i]-x[j],y[i]-y[j])&3;
}
int main(){
	long long ans=0;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&x[i],&y[i]);
		in[i]=(x[i]&1)<<1 | (y[i]&1);
		v[in[i]].push_back(i);
	}
	for(int j=0;j<4;j++){
		int c[4]={}; 
		for(auto i:v[j]){
			c[(x[i]&2) | (y[i]&2)>>1]++;
		}
		for(int i=0;i<4;i++){
			ans+=1LL*c[i]*(c[i]-1)/2*(v[j].size()-c[i]);
			ans+=1LL*c[i]*(c[i]-1)*(c[i]-2)/6;
		}
	}
	for(int i=0;i<n;i++){
		int c[4][4][4]={};
		for(int j=0;j<n;j++){
			if(in[j]==in[i]) continue;
			int xr=(x[j]-x[i])&3,yr=(y[j]-y[i])&3,g=getg(i,j);
			for(int dx=0;dx<4;dx+=2){
				for(int dy=0;dy<4;dy+=2){
					for(int dg=0;dg<4;dg+=2){
						int pxr=xr^dx,pyr=yr^dy,pg=g^dg;
						if(((g+pg+max(dx,dy))&2) == ((xr*pyr - pxr*yr)&2)){
							//printf("match! (%d,%d), (%d,%d), (%d,%d,%d)\n",x[i],y[i],x[j],y[j],pxr,pyr,pg);
							ans+=c[pxr][pyr][pg];
						}
					}
				}
			}
			c[xr][yr][g]++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}