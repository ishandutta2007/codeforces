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

const int N=6005;
const int inf=2e9;
const ll llinf=6e18;

struct node{
	/*
	col=2:  ( a <  b)
	col=1:  ( c >  a)
	col=0:  ()
	*/
	int a,b,c,id;
	int col,nxt;
}a[N];
int n;

void brute(){
	queue<int> q;
	rep(i,1,n-1)q.push(i);
	int now=0,turns=1;
	for(int i=1;i<=2*n;i++){
		int u=q.front();q.pop();
		if(turns==1){
			if(a[now].b>a[u].a)++turns,q.push(u);
			else now=u,turns=1,q.push(now);
		}else if(turns==2){
			if(a[now].c>a[u].a)++turns,q.push(u);
			else now=u,turns=1,q.push(now);
		}
		if(turns==3){
			printf("%d %d\n",a[now].id,i+1);
			exit(0);
		}
	}
}

int main(){
	n=read();rep(i,0,n-1)a[i].a=read(),a[i].b=read(),a[i].c=read(),a[i].id=i;
	if(a[0].a<a[1].a){
		node tmp=a[0];
		rep(i,0,n-2)a[i]=a[i+1];
		a[n-1]=tmp;
	}else{
		node tmp=a[1];
		rep(i,1,n-2)a[i]=a[i+1];
		a[n-1]=tmp;
	}
	// rep(i,0,n-1)printf("Info (i=%d): %d %d %d\n",i,a[i].a,a[i].b,a[i].c);
	
	brute();
	
	rep(i,1,n-1)if(a[i-1].b>a[i].a)a[i].col=2;
	vector<node> nred;
	rep(i,0,n-1){
		a[i].nxt=-1;
		if(a[i].col==2)continue;
		int nxt=(i+1)%n;
		if(a[nxt].col==2)a[i].nxt=nxt,nxt=(nxt+1)%n;
		a[i].col=a[i].c>a[nxt].a,nred.pb(a[i]);
	}
	ll ans=1;
	while(1){
		auto norm=[&](int x){
			if(x<0)x+=SZ(nred);
			return x;
		};
		// (b, )
		vector<pii> stk;
		auto Push=[&](pii x){
			while(!stk.empty()&&stk.back().fir>=x.fir)stk.pop_back();
			stk.pb(x);
		};
		rep(i,0,SZ(nred)-1)Push({nred[i].col==1?-inf:nred[i].b,i});

		int step=inf; // 
		vector<pii> change_nxt;
		rep(i,0,SZ(nred)-1){
			Push({nred[i].col==1?-inf:nred[i].b,i});
			if(!~nred[i].nxt)continue;
			int nxt=nred[i].nxt;
			change_nxt.pb({i,nxt});
			int pos=lower_bound(stk.begin(),stk.end(),make_pair(a[nxt].a,-1))-stk.begin()-1;
			if(pos>=0)ckmin(step,norm(i-stk[pos].sec));
		}
		if(step==inf)return puts("-1 -1"),0;

		ans+=1ll*step*(n-1);
		//  nxt 
		for(auto [x,nxt]:change_nxt){
			if(nred[x].nxt==nxt)nred[x].nxt=-1;
			x=norm(x-step),nred[x].nxt=nxt;
		}
		pair<ll,int> ANS=make_pair(llinf,-1);
		rep(i,0,SZ(nred)-1){
			if(!~nred[i].nxt)continue;
			int nxt=nred[i].nxt;
			// 
			if(nred[i].b<a[nxt].a){
				nred[i].nxt=-1;
				nred.insert(nred.begin()+i+1,a[nxt]);
				nred[i].col=nred[i].c>nred[i+1].a;
				int k=(i+2)%SZ(nred);
				nred[i+1].col=nred[i+1].c>nred[k].a;
			}
			// 
			else if(nred[i].col==1){
				ckmin(ANS,make_pair(ans+a[nxt].id,nred[i].id));
			}
		}
		if(ANS.fir!=llinf){
			printf("%d %lld\n",ANS.sec,ANS.fir);
			return 0;
		}
	}
	return 0;
}