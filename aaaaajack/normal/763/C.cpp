#include<bits/stdc++.h>
#define N 100100
using namespace std;
int a[N];
set<int> in,tin;
int inv(int x,int m){
	int y=m-2,r=1;
	assert(y>=0);
	while(y>0){
		if(y&1) r=1LL*r*x%m;
		x=1LL*x*x%m;
		y>>=1;
	}
	return r;
}
int main(){
	int n,m,sd,cnt=0,tn=0;
	bool rev=false;
	scanf("%d%d",&m,&n);
	sd=m;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		assert(in.count(a[i])==0&&a[i]<m);
		in.insert(a[i]);
	}
	sort(a,a+n);
	if(n==1){
		printf("%d %d\n",a[0],0);
	}
	else if(n==m){
		printf("0 1\n");
	}
	else{
		if(n+n>m){
			for(int i=0;i<m;i++){
				if(!in.count(i)){
					tin.insert(i);
					a[tn++]=i;
				}
			}
			n=tn;
			in=tin;
			rev=true;
		}
		if(n==1&&rev){
			printf("%d %d\n",(a[0]+1)%m,1);
			exit(0);
		}
		a[n]=a[0];
		for(int i=0;i<n;i++){
			int ts=(a[i+1]+m-a[i])%m;
			if(ts<sd) sd=ts,cnt=1;
			else if(ts==sd) cnt++;
		}
		assert(n>cnt);
		int d=1LL*inv(n-cnt,m)*sd%m;
		assert(1LL*d*(n-cnt)%m==sd);
		//printf("%d\n",d);
		int fst=a[0];
		while(in.count((fst+m-d)%m)) fst=(fst+m-d)%m;
		bool flag=true;
		for(int i=0;i<n;i++){
			int tmp=(fst+1LL*i*d)%m;
			if(!in.count(tmp)) flag=false;
		}
		if(flag&&rev) fst=(fst+1LL*n*d)%m;
		if(flag) printf("%d %d\n",fst,d);
		else printf("-1\n");
	}
	return 0;
}