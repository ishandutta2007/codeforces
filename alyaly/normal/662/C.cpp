#include<bits/stdc++.h>
#define gc() getchar()
#define int long long
#define N 1100000
#define mid (l+r)/2
#define inf 999999999999
using namespace std;
int n,m,a[N+1],fl[N+1],poc[N+1],ans=inf;
string s[23];
void putin(){
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>s[i];
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++){
			if(s[i][j]=='1')a[j]+=(1<<i);
		}
		fl[a[j]]++;
	}
}
int lowbit(int x){return x&(-x);}
void ycl(){
	for(int i=1;i<(1<<n);i++)poc[i]=poc[i-lowbit(i)]+1;
	for(int i=0;i<(1<<n);i++)poc[i]=min(poc[i],poc[i^((1<<n)-1)]);
}
void fwt(int*x,int l,int r,int nfl){
	if(r!=l+1)fwt(x,l,mid,nfl),fwt(x,mid,r,nfl);
	if(nfl==1){
		for(int i=l;i<mid;i++){
			int np=x[i],nq=x[i+mid-l];
			x[i]=np+nq,x[i+mid-l]=np-nq;
		}
	}else{
		for(int i=l;i<mid;i++){
			int np=x[i],nq=x[i+mid-l];
			x[i]=(np+nq)/2,x[i+mid-l]=(np-nq)/2;
		}
	}
}
signed main(){
//	freopen("optimize0.in","r",stdin);
//	freopen("optimize.out","w",stdout);
	putin();
	ycl();
	fwt(fl,0,(1<<n),1),fwt(poc,0,(1<<n),1);
	for(int i=0;i<(1<<n);i++)fl[i]*=poc[i];
	fwt(fl,0,(1<<n),-1);
	for(int i=0;i<(1<<n);i++)ans=min(ans,fl[i]);
	cout<<ans<<'\n';
	return 0;
}
/*

*/