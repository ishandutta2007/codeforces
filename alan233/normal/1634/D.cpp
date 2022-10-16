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

int n,a[1005];
//#define zz has_no_jb
inline int Ask(int x,int y,int z){
	cout<<"? "<<x<<" "<<y<<" "<<z<<endl;
	#ifdef zz
		return max(max(a[x],a[y]),a[z])-min(min(a[x],a[y]),a[z]);
	#endif
	cin>>x;
	return x;
}
void Solve(){
	cin>>n;
	#ifdef zz
		for(int i=1;i<=n;++i)cin>>a[i];
	#endif
	int now=3,mx=Ask(1,2,3);
	for(int i=4;i<=n;++i){
		int z=Ask(1,2,i);
		if(z>mx){
			now=i;mx=z;
		}
	}
	int same=mx,jb=2;
	for(int i=3;i<=n;++i){
		if(i==now)continue;
		int z=Ask(1,i,now);
		if(z!=same)same=-1;
		if(z>mx){
			jb=i,mx=z;
		}
	}
	if(jb==2&&now==3){
		if(Ask(1,2,4)==mx){
			cout<<"! "<<1<<" "<<2<<endl;
			return;
		}
	}
	if(~same){
		cout<<"! "<<1<<" "<<now<<endl;
	}
	else{
		cout<<"! "<<jb<<" "<<now<<endl;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}