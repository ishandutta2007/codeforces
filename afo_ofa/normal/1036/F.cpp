#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
/*================Header Template==============*/
const ll lim=1e18;
int T,miu[1005],notprime[1005];
ll n,pre[1005][1005],maxbase[1005],bit[63];
vector<int>prime;
inline void sieve() {
	miu[0]=1,notprime[1]=0;
	for(int i=2;i<=1000;++i) {
		if(!notprime[i]) {
			prime.push_back(i);
			miu[i]=-1;
		}
		for(int j=0;j<prime.size()&&i*prime[j]<1005;++j) {
			notprime[i*prime[j]]=1;
			miu[i*prime[j]]=-miu[i];
			if(!(i%prime[j])) {
				miu[i*prime[j]]=0;
				break;
			}
		}
	}
//	for(int i=2;i<=10;++i)
//		cout<<miu[i]<<" ";
//	cout<<endl;
}
inline ll id(int o,ll x) {
	return maxbase[o]==2?1:upper_bound(pre[o]+1,pre[o]+maxbase[o]+1,n)-pre[o]-2;
}
inline bool overflow(ll x,ll y,ll lim) {
	return lim/y<x;
}
inline ll Kissme(ll x,ll y,ll lim) {
	ll res=1;
	while(y) {
		if(y&1) {
			if(overflow(x,res,lim))
				return 0;
			res*=x;
		}
		y>>=1;
		if(!y)
			break;
		if(overflow(x,x,lim))
			return 0;
		x*=x;
	}
	return res<=lim?res:0;
}
inline ll k_sqrt(ll x,ll k) {
	ll cnt=pow(x,1/(double)k);
	for(;Kissme(cnt+1,k,x);++cnt);
	for(;!Kissme(cnt,k,x);--cnt);
	return cnt;
}
inline void solve(ll x) {
	ll ans=x;
	for(int i=2;i<=5;++i) {
		if(bit[i]>n)
			break;
		ll base=k_sqrt(n,i);
//		cout<<"Pow :"<<i<<" "<<base<<" "<<miu[i]<<endl;
		ans+=(base-1)*miu[i];
	}
	for(int i=6;bit[i]<=n;++i)
		ans+=miu[i]*id(i,n);
	printf("%lld\n",ans-1);
}
inline void prework() {
	bit[0]=1;
	for(int i=1;i<63;++i)
		bit[i]=bit[i-1]<<1;
	for(ll expo=6,base,Ans;expo<=61;maxbase[expo]=base-1,++expo)
		for(pre[expo][1]=1,base=2,Ans=Kissme(base,expo,lim);(pre[expo][base]=Ans)!=0;++base,Ans=Kissme(base,expo,lim));
}
int main() {
	sieve(),prework();
	for(read(T);T--;)read(n),solve(n);
}