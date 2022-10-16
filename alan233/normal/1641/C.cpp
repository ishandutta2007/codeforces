// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mset(s,t) memset(s,t,sizeof(s))
#define mcpy(s,t) memcpy(s,t,sizeof(t))
#define SZ(x) ((int)x.size())
#define pb push_back
#define eb emplace_back
#define fir first
#define sec second

template<class T1,class T2>bool ckmax(T1 &a,T2 b){if(a<b)return a=b,1;else return 0;}
template<class T1,class T2>bool ckmin(T1 &a,T2 b){if(a>b)return a=b,1;else return 0;}

inline int read(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=ch=='-',ch=getchar();
	while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
	return f?-x:x;
}
template<typename T>void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)print(x/10);
	putchar(x%10+'0');
}
template<typename T>void print(T x,char ch){
	print(x),putchar(ch);
}

const int N=500005;

int L[N],R[N],m;

int f[N],n,q,ans[N];

int find(int x){return f[x]==x?x:f[x]=find(f[x]);}

#define ls (u<<1)
#define rs (u<<1|1)
int sum[N<<2];
vector<int> event[N<<2],tmp;
bool vis[N];
void update(int u,int l,int r,int pos){
	if(l==r){
		sum[u]++;
	}else{
		int mid=l+r>>1;
		if(pos<=mid)update(ls,l,mid,pos);
		else update(rs,mid+1,r,pos);
		sum[u]=sum[ls]+sum[rs];
	}
	if(sum[u]>=r-l){
		for(auto &it:event[u]){
			if(!vis[it])tmp.pb(it);
		}
	}
}
void push(int u,int l,int r,int ql,int qr,int id){
	if(ql<=l&&r<=qr){event[u].pb(id);return ;}
	int mid=l+r>>1;
	if(ql<=mid)push(ls,l,mid,ql,qr,id);
	if(qr>mid)push(rs,mid+1,r,ql,qr,id);
}
int query(int u,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)return sum[u];
	int mid=l+r>>1,ret=0;
	if(ql<=mid)ret+=query(ls,l,mid,ql,qr);
	if(qr>mid)ret+=query(rs,mid+1,r,ql,qr);
	return ret;
}

int main(){
	scanf("%d%d",&n,&q);
	rep(i,1,n+1)f[i]=i,ans[i]=-1;
	while(q--){
		int opt=read();
		if(!opt){
			int l=read(),r=read();
			int type=read();
			if(!type){
				for(int i=find(l);i<=r;i=find(i)){
					ans[i]=1;
					update(1,1,n,i);
					f[i]=i+1;
				}
			}else{
				++m,L[m]=l,R[m]=r;
				if(query(1,1,n,l,r)==r-l&&find(l)<=r){
					int t=find(l);
					ans[t]=0;
					f[t]=t+1;
					vis[m]=1;
				}
				push(1,1,n,l,r,m);
			}
			// printf("tmp=");for(auto it:tmp)printf("%d ",it);puts("");
			for(auto &it:tmp){
				if(query(1,1,n,L[it],R[it])==R[it]-L[it]&&!vis[it]&&find(L[it])<=R[it]){
					vis[it]=1;
					int t=find(L[it]);
					// printf("it=%d,t=%d\n",it,t);
					ans[t]=0,f[t]=t+1;
				}
			}
			tmp.clear();
		}else{
			int x=read();
			if(ans[x]==-1)puts("N/A");
			else if(ans[x]==0)puts("YES");
			else puts("NO");
		}
	}
	return 0;
}