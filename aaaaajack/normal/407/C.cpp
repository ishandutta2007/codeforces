#include<cstdio>
#include<algorithm>
#define N 101000
#define Q 1000000007
using namespace std;
int dp[N][110]={0};
struct query{
	int l;
	int r;
	int k;
	query(){}
	query(int _l,int _r,int _k):l(_l),r(_r),k(_k){}
	bool operator<(query a)const{return r>a.r;}
};
int mypow(int x,int n){
	int a=x,ans=1;
	while(n){
		if(n&1) ans=1LL*ans*a%Q;
		n>>=1;
		a=1LL*a*a%Q;
	}
	return ans;
}
int rev(int x){
	return mypow(x,Q-2);
}
int c(int n,int k){
    /*int ans=1,i;
    if(n<k) return 0;
    if(k<0) return 0;
    if(dp[n][k]) return dp[n][k];
    for(i=1;i<=k;i++){
        ans=1LL*ans*(n-i+1)%Q;
        ans=1LL*ans*rev(i)%Q;
        dp[n][i]=ans;
    }
    return ans;*/
	if(k<0||n<k) return 0;
	if(k==0||n==k) return 1;
	if(dp[n][k]) return dp[n][k];
	return dp[n][k]=(c(n-1,k-1)+c(n-1,k))%Q;
}
bool cmp(query a,query b){
	return a.l>b.l;
}
int a[N],add[110]={0};
query q[N],p[N];
int main(){
	int n,m,i,j,t,s;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<m;i++) scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].k);
	for(i=0;i<m;i++) p[i]=q[i];
	sort(q,q+m);
	sort(p,p+m,cmp);
	t=0;
	s=0;
	for(i=n-1;i>=0;i--){
		for(j=1;j<110;j++){
			if(!add[j]) break;
			add[j-1]-=add[j];
			if(add[j-1]<0) add[j-1]+=Q;
		}
		while(t<m&&q[t].r>i){
			for(j=0;j<=q[t].k;j++){
				add[j]+=c(q[t].k+q[t].r-q[t].l-j,q[t].k-j);
				add[j]%=Q;
			}
			t++;
		}
		while(s<m&&p[s].l-2==i){
			add[p[s].k]--;
			s++;
		}
		a[i]+=add[0];
		a[i]%=Q;
	}
	for(i=0;i<n;i++){
		printf("%d",a[i]);
		if(i==n-1) putchar('\n');
		else putchar(' ');
	}
	return 0;
}