#include<cstdio>
#include<algorithm>
#define N 1001000
using namespace std;
char s[N];
int r[2][N],id[2][N],p,cnt[N];
int ls[N],rs[N],lm[N],rm[N];
bool can[N];
inline bool check_same(int i,int j,int t,int n){
	return r[p][i]==r[p][j]&&r[p][(i+t)%n]==r[p][(j+t)%n];
}
int build(){
	int i,n,t,now,pre,c0,c1;
	for(i=0;s[i];i++){
		if(s[i]=='(') r[p][i]=0,cnt[0]++;
		else r[p][i]=1;
	}
	c0=cnt[0];
	c1=cnt[1]=n=i;
	for(i=0;i<n;i++){
		if(s[i]=='(') id[p][--c0]=i;
		else id[p][--c1]=i;
	}
	for(t=1;t<n;t<<=1){
		for(i=n-1;i>=0;i--){
			now=(id[p][i]+n-t)%n;
			id[p^1][--cnt[r[p][now]]]=now;
		}
		now=id[p^1][0];
		r[p^1][now]=0;
		cnt[0]=1;
		for(i=1;i<n;i++){
			cnt[i]=0;
			pre=now;
			now=id[p^1][i];
			if(check_same(pre,now,t,n)){
				r[p^1][now]=r[p^1][pre];
			}
			else{
				r[p^1][now]=r[p^1][pre]+1;
			}
			cnt[r[p^1][now]]++;
		}
		p^=1;
		for(i=1;i<n;i++){
			cnt[i]+=cnt[i-1];
		}
	}
	return n;
}
int main(){
	int i,n,al=0,ar=0,ans;
	scanf("%s",s);
	n=build();
	ls[i]=lm[i]=0;
	for(i=0;i<n;i++){
		if(s[i]=='(') ls[i+1]=ls[i]+1;
		else ls[i+1]=ls[i]-1;
		lm[i+1]=min(lm[i],ls[i+1]);
	}
	rs[n+1]=rm[n+1]=0;
	for(i=n-1;i>=0;i--){
		if(s[i]=='(') rs[i+1]=rs[i+2]+1;
		else rs[i+1]=rs[i+2]-1;
		rm[i+1]=max(rm[i+2],rs[i+1]);
	}
	if(ls[n]>0) ar=ls[n];
	else al=-ls[n];
	for(i=0;i<n;i++){
		if(al+rs[i+1]-rm[i+1]>=0&&al+rs[i+1]+lm[i]>=0) can[i]=true;
	}
	for(i=0;i<n;i++){
		if(can[id[p][i]]){
			ans=id[p][i];
			break;
		}
	}
	for(i=0;i<al;i++) putchar('(');
	printf("%s",s+ans);
	s[ans]=0;
	printf("%s",s);
	for(i=0;i<ar;i++) putchar(')');
	putchar('\n');
	return 0;
}