/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[200100],b[200100],A[200100],B[200100],_a,_b;
int P[200100],Q[200100];
bool che(int K){
	// printf("CHECK:%d\n",K);
	ll mxa=0,mxb=0,tot=0,cnt=0;
	for(int i=1,j=m;i<=n;i++){for(;j;j--)if(a[A[i]]+b[B[j]]<=K)break;P[i]=j,tot+=m-j;}
	for(int i=1,j=n;i<=m;i++){for(;j;j--)if(b[B[i]]+a[A[j]]<=K)break;Q[i]=j;}
	// for(int i=1;i<=n;i++)printf("%d ",P[i]);puts("");
	// for(int i=1;i<=m;i++)printf("%d ",Q[i]);puts("");
	mxa=tot,cnt=tot;
	for(int i=1,j=0;i<=n;i++){
		cnt-=m-max(P[i],j);
		cnt+=min(P[i],j);
		for(;j<m;j++){
			int bon=min(Q[j+1],i)-(n-max(Q[j+1],i));
			if(bon<0)break;
			cnt+=bon;
		}
		// printf("<%d,%d>:%d\n",i,j,cnt);
		mxa=max(mxa,cnt);
	}
	mxb=tot-1,cnt=tot-1;
	for(int i=1,j=0;i<=n;i++){
		cnt-=m-max(P[i],j);
		cnt+=min(P[i],j);
		if(i==_a&&j<_b)cnt++;
		// printf("<%d,%d>:%d\n",i,j,cnt);
		for(;j<m;j++){
			int bon=min(Q[j+1],i)-(n-max(Q[j+1],i));
			if(j+1==_b&&i<_a)bon++;
			if(bon<0)break;
			cnt+=bon;
		}
		// printf("<%d,%d>:%d\n",i,j,cnt);
		mxb=max(mxb,cnt);
	}
	// printf("%d,%d\n",mxa,mxb);
	return mxa==mxb;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),A[i]=i;sort(A+1,A+n+1,[](int x,int y){return a[x]<a[y];});
	for(int i=1;i<=m;i++)scanf("%d",&b[i]),B[i]=i;sort(B+1,B+m+1,[](int x,int y){return b[x]<b[y];});
	_a=find(A+1,A+n+1,1)-A,_b=find(B+1,B+m+1,1)-B;
	// che(24487163);
	int l=0,r=a[1]+b[1];
	while(l<r){
		int mid=(l+r)>>1;
		if(che(mid))r=mid;else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}