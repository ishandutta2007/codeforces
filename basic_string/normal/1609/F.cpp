#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+3;
ll a[N],ans;
int now;
int pc[N],n;
bool b[N];
struct FW{
int a[N],b[N];
void clr(){memset(a,0,sizeof a),memset(b,0,sizeof b);}
void add(int x,int y){for(int z=x*y;x<=n;x+=x&-x)a[x]+=y,b[x]+=z;}
int sum(int x){int u=0,v=0;for(int i=x;i;i-=i&-i)u+=a[i],v+=b[i];return(x+1)*u-v;}
void ad(int l,int r){add(l,1),add(r+1,-1);}
void dl(int l,int r){add(l,-1),add(r+1,1);}
int sm(int l,int r){return sum(r)-sum(l-1);}
}t[2];
int mx[N],mn[N];
void del(bool b,int l,int r){
	now-=t[!b].sm(l,r),t[b].dl(l,r);
}
void add(bool b,int l,int r){
	now+=t[!b].sm(l,r),t[b].ad(l,r);
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int i,j,k,tmx,tmn,la;
	cin>>n;
	for(i=1;i<=n;++i)cin>>a[i],pc[i]=__builtin_popcountll(a[i]);
	for(i=0;i<64;++i){
		for(j=1;j<=n;++j)if(pc[j]==i)goto gg;
		continue;
		gg:;
		t[0].clr(),t[1].clr();
		tmx=tmn=0;now=0;
		for(j=1;j<=n;++j){
			if(pc[j]==i)b[j]=1;
			else b[j]=0;
			while(tmx&&a[k=mx[tmx]]<=a[j]){
				--tmx;
				if(b[k]^b[j]){
					if(b[k])del(0,mx[tmx]+1,k);
					else add(0,mx[tmx]+1,k);
				}
			}
			while(tmn&&a[k=mn[tmn]]>=a[j]){
				--tmn;
				if(b[k]^b[j]){
					if(b[k])del(1,mn[tmn]+1,k);
					else add(1,mn[tmn]+1,k);
				}
			}
			mx[++tmx]=j,mn[++tmn]=j;
			if(b[j])add(0,j,j),add(1,j,j);
			ans+=now;
		}
	}
	cout<<ans;
	return 0;
}