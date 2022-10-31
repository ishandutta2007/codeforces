#include<bits/stdc++.h>
#define N 300100
using namespace std;
int lt[20][N*2],rt[20][N*2];
int d[N];
void build(int s,int m){
	for(int i=m-1;i>0;i--){
		lt[s][i]=min(lt[s][i*2],lt[s][i*2+1]);
		rt[s][i]=max(rt[s][i*2],rt[s][i*2+1]);
	}
}
int ql(int s,int sl,int sr,int m){
	sl+=m,sr+=m+1;
	int res=m-1;
	while(sl<sr){
		if(sl&1) res=min(res,lt[s][sl++]);
		if(sr&1) res=min(res,lt[s][--sr]);
		sl>>=1,sr>>=1;
	}
	return res;
}
int qr(int s,int sl,int sr,int m){
	sl+=m,sr+=m+1;
	int res=0;
	while(sl<sr){
		if(sl&1) res=max(res,rt[s][sl++]);
		if(sr&1) res=max(res,rt[s][--sr]);
		sl>>=1,sr>>=1;
	}
	return res;
}
int main(){
	int n,m;
	scanf("%d",&n);
	m=n*3;
	for(int i=0;i<n;i++) scanf("%d",&d[i]);
	for(int i=n;i<m;i++) d[i]=d[i-n];
	for(int i=0;i<m;i++){
		rt[0][m+i]=min(i+d[i],m-1);
		lt[0][m+i]=max(i-d[i],0);
	}
	build(0,m);
	for(int j=1;j<20;j++){
		for(int i=0;i<m;i++){
			lt[j][m+i]=ql(j-1,lt[j-1][m+i],rt[j-1][m+i],m);
			rt[j][m+i]=qr(j-1,lt[j-1][m+i],rt[j-1][m+i],m);
		}
		build(j,m);
	}
	for(int i=n;i<n+n;i++){
		int cl=i,cr=i,ans=0;
		for(int s=19;s>=0;s--){
			int tr=qr(s,cl,cr,m),tl=ql(s,cl,cr,m);
			if(tr-tl<n-1){
				cr=tr;
				cl=tl;
				ans+=1<<s;
			}
		}
		if(cr-cl<n-1) ans++;
		printf("%d ",ans);
	}
	return 0;
}