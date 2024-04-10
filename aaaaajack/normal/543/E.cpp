#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<utility>
#define M 19
#define N 200010
#define B (N*2)
#define inf 1023456789
using namespace std;
//sum*(2N)^2+min*(2N)+lc
//offset=(N,N,1)
long long tr[M][N*2];
int buffer[2][N*2],a[N],p,mlen;
int nxt[N];
char single[N];
const long long zero=1LL*N*B*B+1LL*N*B+1;
bool cmp(int i,int j){
	return a[abs(i)]<a[abs(j)];
}
void build(int n,int m){
	int i,l,r,md,nid,sum,mn,lsum,rsum,lmn,rmn,lc,rc,lv=0;
	bool final;
	for(i=0;i<n-m;i++){
		buffer[p][i*2]=i;
		buffer[p][i*2+1]=-(i+m);
	}
	sort(buffer[p],buffer[p]+(n-m)*2,cmp);
	nxt[0]=n-m;
	while(1){
		final=true;
		for(l=0;l<n-m;l=r){
			r=nxt[l];
			if(l+1==r){
				single[l]++;
				if(buffer[p][l*2]>=0){
					tr[lv][l*2]=zero-1LL*B*B-B;
					tr[lv][l*2+1]=zero;
				}
				else{
					tr[lv][l*2]=zero+1LL*B*B;
					tr[lv][l*2+1]=zero;
				}
				continue;
			}
			final=false;
			md=(l+r)/2;
			nxt[l]=md;
			nxt[md]=r;
			lc=l*2;
			rc=md*2;
			for(i=l*2;i<r*2;i++){
				if(buffer[p][i]>=0){
					nid=buffer[p][i];
				}
				else{
					nid=-buffer[p][i]-m;
				}
				if(nid<md){
					buffer[p^1][lc++]=buffer[p][i];
				}
				else{
					buffer[p^1][rc++]=buffer[p][i];
				}
				tr[lv][i]=zero+lc-1;
			}
		}
		if(final) break;
		p^=1;
		lv++;
	}
	lv--;
	while(lv>=0){
		for(l=0;l<n-m;l=nxt[l]){
			if(single[l]>1){
				single[l]--;
				continue;
			}
			md=nxt[l];
			nxt[l]=r=nxt[md];
			if(l+1==r){
				continue;
			}
			for(i=l*2;i<r*2;i++){
				lc=tr[lv][i]%B-1;
				rc=md*2+(i-lc)-1;
				if(lc<l*2){
					lsum=lmn=0;
				}
				else{
					lsum=tr[lv+1][lc]/B/B-N;
					lmn=tr[lv+1][lc]/B%B-N;
				}
				if(i==lc){
					rsum=rmn=0;
				}
				else{
					rsum=tr[lv+1][rc]/B/B-N;
					rmn=tr[lv+1][rc]/B%B-N;
				}
				sum=lsum+rsum;
				mn=min(lsum+rmn,lmn);
				tr[lv][i]+=1LL*sum*B*B+1LL*mn*B;
			}
		}
		lv--;
	}
	memcpy(buffer[0],a,sizeof(int)*m);
	sort(buffer[0],buffer[0]+m);
	memcpy(buffer[1],a,sizeof(int)*(n-m));
	memcpy(buffer[1]+n-m,a+m,sizeof(int)*(n-m));
	sort(buffer[1],buffer[1]+(n-m)*2);
}
int qpsum(int lv,int l,int r,int qr,int i){
	if(i<l*2) return 0;
	if(qr==r) return tr[lv][i]/B/B-N;
	int md=(l+r)/2,lc=tr[lv][i]%B-1,rc=md*2+i-lc-1;
	if(qr<=md) return qpsum(lv+1,l,md,qr,lc);
	else return qpsum(lv+1,l,md,md,lc) + qpsum(lv+1,md,r,qr,rc);
}
//first:sum second:min
//return value: (sum+N)*B+(min+N)
long long qry(int lv,int l,int r,int ql,int qr,int i){
	if(i<l*2) return zero/B;
	if(l==ql&&r==qr){
		return tr[lv][i]/B;
	}
	int md=(l+r)/2,lc=tr[lv][i]%B-1,rc=md*2+i-lc-1;
	if(qr<=md){
		return qry(lv+1,l,md,ql,qr,lc);
	}
	else if(ql>=md){
		return qry(lv+1,md,r,ql,qr,rc);
	}
	else{
		long long lres=qry(lv+1,l,md,ql,md,lc);
		long long rres=qry(lv+1,md,r,md,qr,rc);
		return (lres/B+rres/B-N)*B+min(lres%B,lres/B+rres%B-N);
	}
}
int cal(int l,int r,int n,int m,int q){
	l--;
	r--;
	int base=lower_bound(buffer[0],buffer[0]+m,q)-buffer[0];
	int i=(upper_bound(buffer[1],buffer[1]+(n-m)*2,q-1)-buffer[1])-1;
	return base+(l?qpsum(0,0,n-m,l,i):0)+(l<r?qry(0,0,n-m,l,r,i)%B-N:0);
}
int main(){
	int n,m,q,ans=0,l,r,x,i;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	build(n,m);
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d",&l,&r,&x);
		x^=ans;
		ans=cal(l,r,n,m,x);
		printf("%d\n",ans);
	}
	return 0;
}