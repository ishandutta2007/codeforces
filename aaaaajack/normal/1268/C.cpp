#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define N 300100
using namespace std;
int f[N],a[N],b[N];
long long ans[N];
void upd(int x){
	while(x<N){
		f[x]++;
		x+=x&-x;
	}
}
int sum(int x){
	int r=0;
	while(x){
		r+=f[x];
		x-=x&-x;
	}
	return r;
}
bool cmp(int i,int j){
	return a[i]<a[j];
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=i;
	}
	sort(b+1,b+n+1,cmp);
	long long psum=0;
	set<int> in;
	int ml=0,mr=n+1;
	for(int i=1;i<=n;i++){
		upd(b[i]);
		int pos=sum(b[i]);
		psum-=abs(pos-1-(i-pos)); //remove contribution of b[i]
		ans[i]=ans[i-1]+i-pos;
		in.insert(b[i]);
		if(b[i]<ml){
			psum+=b[i]-pos; //add left decre
			psum-=(ml-sum(ml))-(b[i]-pos); //minus mid cancel
			psum+=(n-i)-(ml-sum(ml));//add right incre
			if(i&1) mr=ml;
			else ml=*(--in.lower_bound(ml));
		}
		else if(b[i]>mr){
			psum+=mr-sum(mr); //add left decre
			psum-=(b[i]-pos)-(mr-sum(mr)); //minus mid cancel
			psum+=(n-i)-(b[i]-pos);//add right incre
			if(i&1) ml=mr;
			else mr=*in.upper_bound(mr);
		}
		else{
			psum+=n-i;
			ml=mr=b[i];
		}
		//printf("%d: %lld %lld\n",b[i],psum,ans[i]);
		printf("%lld ",ans[i]+(1LL*i*(n-i)-psum)/2);
	}
	puts("");
	return 0;
}