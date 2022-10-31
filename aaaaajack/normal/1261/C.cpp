#include<bits/stdc++.h>
#define N 1001000
using namespace std;
int ps[N],tag[N];
int ans[N];
char s[N];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",s+i*m);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			ps[i*m+j]=(s[i*m+j]=='X'?1:0);
			if(i>0) ps[i*m+j]+=ps[(i-1)*m+j];
			if(j>0) ps[i*m+j]+=ps[i*m+j-1];
			if(i>0&&j>0) ps[i*m+j]-=ps[(i-1)*m+(j-1)];
		}
	}
	int l=0,r=10000;
	while(l+1<r){
		int x=(l+r)/2;
		memset(tag,0,sizeof(tag));
		memset(ans,0,sizeof(ans));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(i+x*2>=n||j+x*2>=m) continue;
				int tsum=ps[(i+x*2)*m+(j+x*2)];
				if(i>0) tsum-=ps[(i-1)*m+(j+x*2)];
				if(j>0) tsum-=ps[(i+x*2)*m+j-1];
				if(i>0&&j>0) tsum+=ps[(i-1)*m+(j-1)];
				if(tsum==(x+x+1)*(x+x+1)){
					ans[(i+x)*m+(j+x)]++;
					tag[(i+x*2)*m+(j+x*2)]++;
					if(i>0) tag[(i-1)*m+(j+x*2)]--;
					if(j>0) tag[(i+x*2)*m+j-1]--;
					if(i>0&&j>0) tag[(i-1)*m+(j-1)]++;
				}
			}
		}
		for(int i=n-1;i>=0;i--){
			for(int j=m-1;j>=0;j--){
				if(i<n-1) tag[i*m+j]+=tag[(i+1)*m+j];
				if(j<m-1) tag[i*m+j]+=tag[i*m+j+1];
				if(i<n-1&&j<m-1) tag[i*m+j]-=tag[(i+1)*m+(j+1)];
			}
		}
		bool flag=true;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(s[i*m+j]=='X' && tag[i*m+j]==0) flag=false;
			}
		}
		if(flag) l=x;
		else r=x;
	}
	printf("%d\n",l);
	int x=l;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i+x*2>=n||j+x*2>=m) continue;
			int tsum=ps[(i+x*2)*m+(j+x*2)];
			if(i>0) tsum-=ps[(i-1)*m+(j+x*2)];
			if(j>0) tsum-=ps[(i+x*2)*m+j-1];
			if(i>0&&j>0) tsum+=ps[(i-1)*m+(j-1)];
			if(tsum==(x+x+1)*(x+x+1)){
				ans[(i+x)*m+(j+x)]++;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(ans[i*m+j]) putchar('X');
			else putchar('.');
		}
		puts("");
	}
	return 0;
}