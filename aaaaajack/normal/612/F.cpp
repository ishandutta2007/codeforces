#include<bits/stdc++.h>
#define N 2020
using namespace std;
int a[N],b[N];
tuple<int,int,int> ch[N][N][2];
int dp[N][N][2];
bool cmp(int i,int j){
	return a[i]<a[j]||a[i]==a[j]&&i<j;
}
inline int dis(int i,int j,int n){
	return min((j+n-i)%n,(i+n-j)%n);
}
inline int mv(int s,int d,int st,int m){
	return st+(s-st+d)%m;
}
bool upd(int &x,int y){
	if(y<x){
		x=y;
		return true;
	}
	return false;
}
tuple<int,int,int> get_nxt(tuple<int,int,int> cur){
	int l=get<0>(cur),r=get<1>(cur),s=get<2>(cur);
	return ch[l][r][s];
}
int get_pos(tuple<int,int,int> cur){
	return get<2>(cur)?b[get<1>(cur)]:b[get<0>(cur)];
}
int main(){
	int n;
	scanf("%d%d",&n,&b[0]);
	b[0]--;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[i+1]=i;
	}
	sort(b+1,b+n+1,cmp);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0][0]=dp[0][0][1]=0;
	int st=1,pst=0;
	while(st<=n){
		int ed=st;
		while(ed<=n && a[b[ed]]==a[b[st]]) ed++;
		int m=ed-st;
		for(int i=pst;i<st;i++){
			for(int l=st;l<ed;l++){
				for(int s=0;s<2;s++){
					int r=mv(l,m-1,st,m);
					if(upd(dp[l][r][0],dp[i][i][s]+dis(b[i],b[l],n))) ch[l][r][0]=make_tuple(i,i,s);
					if(upd(dp[l][r][1],dp[i][i][s]+dis(b[i],b[r],n))) ch[l][r][1]=make_tuple(i,i,s);
				}
			}
		}
		for(int d=m-1;d>0;d--){
			for(int l=st;l<ed;l++){
				int r=mv(l,d,st,m);
				for(int s=0;s<2;s++){
					int cur=s?b[r]:b[l];
					int ml=s?l:mv(l,1,st,m),mr=s?mv(r,m-1,st,m):r;
					if(upd(dp[ml][mr][0],dp[l][r][s]+dis(cur,b[ml],n))) ch[ml][mr][0]=make_tuple(l,r,s);
					if(upd(dp[ml][mr][1],dp[l][r][s]+dis(cur,b[mr],n))) ch[ml][mr][1]=make_tuple(l,r,s);
				}
			}
		}
		pst=st;
		st=ed;
	}
	int bi=pst,bs=0;
	vector<int> ans;
	for(int i=pst;i<st;i++){
		for(int s=0;s<2;s++){
			if(dp[i][i][s]<dp[bi][bi][bs]){
				bi=i;
				bs=s;
			}
		}
	}
	printf("%d\n",dp[bi][bi][bs]);
	tuple<int,int,int> cur(bi,bi,bs);
	while(get<0>(cur)){
		ans.push_back(get_pos(cur));
		cur=get_nxt(cur);
	}
	ans.push_back(b[0]);
	for(int i=ans.size()-1;i>0;i--){
		if((ans[i-1]+n-ans[i])%n<=n/2) printf("+");
		else printf("-");
		printf("%d\n",dis(ans[i],ans[i-1],n));
	}
	return 0;
}