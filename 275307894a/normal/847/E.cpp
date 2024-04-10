#include<cstdio>
#include<algorithm>
#define abs(x) ((x)>0?(x):-(x))
using namespace std;
int n,m,k,x,y,z,a[100039],b[100039],ah,bh,head,d[100039];
long long l,r,mid,now,ans,tot,pus;
char c;
inline int check(long long mid){
	register int i;head=1;
	for(i=1;i<=bh;i++) b[i]=d[i];
	for(i=1;i<=ah;i++){
		now=mid-abs(a[i]-b[head]);
		if(now>=0){
			pus=head;head++;ans=now;
			while(head<=bh&&b[head]<=a[i])b[head]=b[head-1],head++;
			if(a[i]<=b[pus]){
				while(head<=bh&&now-(b[head]-b[head-1])>=0) now-=b[head]-b[head-1],head++;
			}
			else{
				tot=head;
			    while(head<=bh&&now-2*(b[head]-a[i])>=0) head++;
			    if(a[i]-b[pus]<b[head]-a[i]) {
			    	now=ans-(a[i]-b[pus]);head=tot;
			    	while(head<=bh&&now-(b[head]-a[i])>=0) head++;
			    }
			}
			if(head==bh+1) return 1;
		}
	}
	return 0;
}
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		c=getchar();
		while(c!='P'&&c!='.'&&c!='*')c=getchar();
		if(c=='P') a[++ah]=i;
		if(c=='*') b[++bh]=i;
	}
	sort(b+1,b+bh+1);
	sort(a+1,a+ah+1);
	for(i=1;i<=bh;i++) d[i]=b[i];
	l=0;r=(long long)n*n;
	while(l+1<r){
		mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid;
	}
	printf("%lld\n",r);
}