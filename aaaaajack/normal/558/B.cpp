#include<cstdio>
#define M 1001000
#define N 100100
using namespace std;
int a[N],l[M],r[M];
int cnt[M];
int main(){
	int n,i,mcnt,mx=0,ans=-1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
		r[a[i]]=i;
		if(cnt[a[i]]==1) l[a[i]]=i;
		if(cnt[a[i]]>mx) mx=cnt[a[i]];
	}
	for(i=0;i<M;i++){
		if(cnt[i]==mx&&(ans==-1||r[i]-l[i]<r[ans]-l[ans])){
			ans=i;
		}
	}
	printf("%d %d\n",l[ans]+1,r[ans]+1);
	return 0;
}