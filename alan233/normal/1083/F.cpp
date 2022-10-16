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

const int N=200005;

int gg=0,num=0;

struct BLOCK{
	vector<int> a;
	int be[N],lazy[555];
	int cnt[555][1<<14];
	int n,B,las,flag;
	void build(){
		// printf("a={");for(auto it:a)printf("%d ",it);puts("}");
		// printf("las=%d,flag=%d\n",las,flag);
		gg+=(flag&&las);
		n=SZ(a),B=max(1,(int)(1.1*sqrt(n)));
		rep(i,0,n-1)be[i]=i/B;
		rep(i,0,n-1)cnt[be[i]][a[i]]++,num+=!a[i];
	}
	int calc(int bid){
		return cnt[bid][lazy[bid]];
	}
	void update(int p,int dlt){
		int bp=be[p];
		num-=calc(bp);
		rep(i,bp*B,min(n-1,(bp+1)*B-1)){
			cnt[bp][a[i]]--;
			a[i]^=lazy[bp];
			if(i>=p)a[i]^=dlt;
			cnt[bp][a[i]]++;
		}
		lazy[bp]=0;
		num+=calc(bp);
		rep(i,bp+1,(n-1)/B){
			num-=calc(i);
			lazy[i]^=dlt;
			num+=calc(i);
		}
		gg-=(flag&&las);
		las^=dlt;
		gg+=(flag&&las);
	}
	void clear(){
		for(int i=0;i<=(n-1)/B;i++){
			for(int j=i*B;j<=min(n-1,(i+1)*B-1);j++)
				cnt[i][a[j]]--;
			lazy[i]=0;
		}
		a.clear();
	}
}blk;

int inia[N],inib[N];
int a[N],n,k,Q;

int GG[N],NUM[N];

void getans(int num,int gg){
	if(gg)puts("-1");
	else print(n-num,'\n');
}

vector<array<int,3>> event[N];

int main(){
	n=read(),k=read(),Q=read();
	rep(i,0,n-1)inia[i]=read();
	rep(i,0,n-1)inib[i]=read(),a[i]=inia[i]^inib[i];
	per(i,n-1,1)a[i]^=a[i-1]; // d[i]=a[i]^a[i-1]
	
	// rep(i,n-k+1,n-1)blk[i%k].flag=1;
	rep(i,0,n-1){
		if(i>=k)a[i]^=a[i-k];
		// blk[i%k].a.pb(a[i]),blk[i%k].las=a[i];
	}
	// rep(i,0,k-1)blk[i].build();

	rep(i,1,Q){
		char opt[3];int p,val,dlt;
		scanf("%s%d%d",opt,&p,&val);
		p--;
		if(opt[0]=='a'){
			dlt=inia[p]^val,inia[p]=val;
		}else{
			dlt=inib[p]^val,inib[p]=val;
		}
		event[p%k].pb({i,p/k,dlt});
		if(p<n-1)event[(p+1)%k].pb({i,(p+1)/k,dlt});
	}

	rep(i,0,k-1){
		num=gg=0;
		int qaq=0;
		for(int j=i;j<n;j+=k)
			blk.a.pb(a[j]),blk.las=a[j],qaq=j;
		blk.flag=qaq>=n-k+1;
		blk.build();
		NUM[0]+=num,GG[0]+=gg;
		for(auto [tim,pos,dlt]:event[i]){
			num=gg=0;
			blk.update(pos,dlt);
			NUM[tim]+=num,GG[tim]+=gg;
		}
		blk.clear();
	}
	rep(i,0,Q){
		if(i)NUM[i]+=NUM[i-1],GG[i]+=GG[i-1];
		getans(NUM[i],GG[i]);
	}
	return 0;
}