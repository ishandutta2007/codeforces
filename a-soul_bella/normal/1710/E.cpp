//http://www.zhengruioi.com/submission/343724
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[300005],b[300005],l,r,mid,sx,sy,na[300005],nb[300005],nw;
long long tmp,tt,t1,t2;
int Val(const int& x,const int& id,const int& ni,const int& y){
	return x-(id==ni&&x>=y);
}
bool Check(const int& lm){
	nw=tmp=0;
	for(int i=1;i<=n;++i){
		while(nw<m&&a[i]+b[m-nw]>=lm)++nw;
		na[i]=nw,tmp+=nw;
	}
	nw=0;
	for(int i=1;i<=m;++i){
		while(nw<n&&a[n-nw]+b[i]>=lm)++nw;
		nb[i]=nw;
	}
	nw=0,t1=tmp,t2=tmp-1,tt=tmp;
	for(int i=0;i<=n;++i,tt+=min(nw,m-na[i])-min(m-nw,na[i])){
		while(nw<m&&min(i,n-nb[nw+1])>=min(n-i,nb[nw+1]))++nw,tt+=min(i,n-nb[nw])-min(n-i,nb[nw]);
		t1=max(t1,tt);
	}
	tt=tmp-1,nw=0;
	for(int i=0;i<=n;++i,tt+=min(nw,m-na[i])-Val(min(m-nw,na[i]),i,sx,m-sy+1)){
		while(nw<m&&min(i,n-nb[nw+1])>=Val(min(n-i,nb[nw+1]),nw+1,sy,n-sx+1))++nw,tt+=min(i,n-nb[nw])-Val(min(n-i,nb[nw]),nw,sy,n-sx+1);
		t2=max(t2,tt);
	}
	return t1==t2+1;
}
signed main(){
	cin >> n >> m;
	for(int i=1;i<=n;++i) cin >> a[i];
	for(int i=1;i<=m;++i) cin >> b[i];
	sx=a[1],sy=b[1];
	sort(a+1,a+n+1),sort(b+1,b+m+1);
	l=a[1]+b[1],r=sx+sy;
	for(int i=1;i<=n;++i)if(a[i]==sx){
		sx=i;
		break;
	}
	for(int i=1;i<=m;++i)if(b[i]==sy){
		sy=i;
		break;
	}
	while(l<r)mid=l+r+1>>1,Check(mid)?l=mid:r=mid-1;
	cout << l;
	return 0;
}