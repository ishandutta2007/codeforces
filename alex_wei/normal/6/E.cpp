#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define sort(x) sort(all(x))
#define rev(x) reverse(all(x))

char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;

#ifdef __WIN64
	#define gc getchar()
#else
	#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
#endif
#define pc(x) (*O++=x)
#define flush() fwrite(obuf,O-obuf,1,stdout)

inline int read(){
	int x=0,sign=0; char s=getchar();
	while(!isdigit(s))sign|=s=='-',s=getchar();
	while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=getchar();
	return sign?-x:x;
}
void print(int x){
	if(x>9)print(x/10);
	pc(x%10+'0');
}

const int N=1e5+5;
int n,k,len,h[N],mi[N<<2],ma[N<<2];
void build(int l,int r,int x){
	if(l==r){
		mi[x]=ma[x]=h[l];
		return;
	}
	int m=l+r>>1;
	build(l,m,x<<1),build(m+1,r,x<<1|1);
	mi[x]=min(mi[x<<1],mi[x<<1|1]);
	ma[x]=max(ma[x<<1],ma[x<<1|1]);
}
pii upd(pii a,pii b){
	return {min(a.fi,b.fi),max(a.se,b.se)};
}
pii query(int l,int r,int ql,int qr,int x){
	if(ql<=l&&r<=qr)return {mi[x],ma[x]};
	int m=l+r>>1; pii ans={1e9,-1e9};
	if(ql<=m)ans=upd(ans,query(l,m,ql,qr,x<<1));
	if(m<qr)ans=upd(ans,query(m+1,r,ql,qr,x<<1|1));
	return ans;
}
vector <int> ans;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>h[i];
	int l=1; build(1,n,1);
	for(int i=1;i<=n;i++){
		pii tmp=query(1,n,l,i,1);
		while(tmp.se-tmp.fi>k)tmp=query(1,n,++l,i,1);
		if(i-l+1>len)len=i-l+1,ans.clear();
		if(i-l+1>=len)ans.push_back(i);
	}
	cout<<len<<" "<<ans.size()<<endl;
	for(auto it:ans)cout<<it-len+1<<" "<<it<<endl;
    return 0;
}