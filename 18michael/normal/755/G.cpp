#include<bits/stdc++.h>
#define LL long long
using namespace std;
namespace Poly
{
	const int mod=998244353,_G=3,_Gi=332748118,Mx=2100000;
	int _rev[Mx+2],_w[Mx+2],_wi[Mx+2],_inv[Mx+2];
	typedef pair<int,int> P;
	inline void Print(vector<int> A)
	{
		for(int i=0;i<A.size();++i)printf("%d ",A[i]);
		puts("");
	}
	inline LL Pow(int a,int b)
	{
		if(!b)return 1;
		LL c=Pow(a,b>>1);
		c=(c*c)%mod;
		if(b&1)c=(c*a)%mod;
		return c;
	}
	inline void add(int &x,int y)
	{
		if((x+=y)>=mod)x-=mod;
	}
	inline vector<int> Add(vector<int> A,vector<int> B)
	{
		int n=max(A.size(),B.size());
		A.resize(n);
		for(int i=0;i<n;++i)add(A[i],B[i]);
		return A;
	}
	inline vector<int> Mul(vector<int> A,int k)
	{
		for(int i=0;i<A.size();++i)add(A[i]=((LL)A[i]*k)%mod,mod);
		return A;
	}
	inline void Init()
	{
		int len,mid,W,Wi;
		len=(1<<(int)log2(Mx)),mid=len>>1,W=Pow(_G,(mod-1)/len),Wi=Pow(_Gi,(mod-1)/len),_w[mid]=_wi[mid]=_inv[1]=1;
		for(int i=2;i<=Mx;++i)_inv[i]=((LL)(mod-mod/i)*_inv[mod%i])%mod;
		for(int i=mid+1;i<len;++i)_w[i]=((LL)_w[i-1]*W)%mod,_wi[i]=((LL)_wi[i-1]*Wi)%mod;
		for(int i=mid-1;i>=0;--i)_w[i]=_w[i<<1],_wi[i]=_wi[i<<1];
	}
	inline void NTT(vector<int> &A,bool o)
	{
		int n=A.size(),tmp;
		for(int i=0;i<n;++i)if(i<_rev[i])swap(A[i],A[_rev[i]]);
		for(int i=1;i<n;i<<=1)for(int j=0;j<n;j+=(i<<1))for(int k=0;k<i;++k)tmp=((LL)A[i+j+k]*(o? _w[i+k]:_wi[i+k]))%mod,add(A[i+j+k]=A[j+k],mod-tmp),add(A[j+k],tmp);
	}
	inline vector<int> Mul(vector<int> A,vector<int> B)
	{
		int n=A.size()-1,m=B.size()-1,t,len,mid,W,Wi,inv;
		for(t=-1,len=1;len<=n+m;len<<=1,++t);
		mid=len>>1,W=Pow(_G,(mod-1)/len),Wi=Pow(_Gi,(mod-1)/len),_w[mid]=_wi[mid]=1,inv=Pow(len,mod-2);
		for(int i=1;i<len;++i)_rev[i]=(_rev[i>>1]>>1)|((i&1)<<t);
		for(int i=mid+1;i<len;++i)_w[i]=((LL)_w[i-1]*W)%mod,_wi[i]=((LL)_wi[i-1]*Wi)%mod;
		for(int i=mid-1;i>=0;--i)_w[i]=_w[i<<1],_wi[i]=_wi[i<<1];
		A.resize(len),B.resize(len),NTT(A,1),NTT(B,1);
		for(int i=0;i<len;++i)A[i]=((LL)A[i]*B[i])%mod;
		NTT(A,0),A.resize(n+m+1);
		for(int i=0;i<A.size();++i)A[i]=((LL)A[i]*inv)%mod;
		return A;
	}
	inline vector<int> Inv(vector<int> &A,int k)
	{
		vector<int> B,C;
		B.push_back(Pow(A[0],mod-2));
		for(int l=2;l<=(k<<1);l<<=1)(C=A).resize(l),C=Mul(Mul(C,B),-1),add(C[0],2),(B=Mul(B,C)).resize(l);
		return B.resize(k),B;
	}
	inline int RND()
	{
		int res=rand();
		res*=rand(),res^=rand();
		return abs(res);
	}
	inline int Cipolla(int k)
	{
		if(!k)return 0;
		int a,b=((mod+1)>>1),I;
		for(;Pow((a=RND(),I=((((LL)a*a-k)%mod)+mod)%mod),(mod-1)>>1)==1;);
		P p=P(1,0),t=P(a,1);
		for(;b;b>>=1)
		{
			if(b&1)p=P(((LL)p.first*t.first+(((LL)p.second*t.second)%mod)*I)%mod,((LL)p.first*t.second+(LL)t.first*p.second)%mod);
			t=P(((LL)t.first*t.first+(((LL)t.second*t.second)%mod)*I)%mod,((LL)t.first*t.second*2)%mod);
		}
		return min(p.first,mod-p.first);
	}
	inline vector<int> Sqrt(vector<int> &A,int k)
	{
		vector<int> B,C;
		B.push_back(Cipolla(A[0]));
		for(int l=2;l<=(k<<1);l<<=1)(C=A).resize(l),(B=Mul(Mul(Add(Mul(B,B),C),Inv(B,l)),(mod+1)/2)).resize(l);
		return B.resize(k),B;
	}
	inline vector<int> Der(vector<int> A)
	{
		for(int i=1;i<A.size();++i)A[i-1]=((LL)A[i]*i)%mod;
		return A.pop_back(),A;
	}
	inline vector<int> Int(vector<int> A)
	{
		A.push_back(0);
		for(int i=A.size()-1;i;--i)A[i]=((LL)A[i-1]*_inv[i])%mod;
		return A[0]=0,A;
	}
	inline vector<int> Ln(vector<int> A,int k)
	{
		return (A=Int(Mul(Der(A),Inv(A,k)))).resize(k),A;
	}
	inline vector<int> Exp(vector<int> &A,int k)
	{
		vector<int> B,C;
		B.push_back(1);
		for(int l=2;l<=(k<<1);l<<=1)(C=A).resize(l),C=Add(C,Mul(Ln(B,l),-1)),add(C[0],1),(B=Mul(B,C)).resize(l);
		return B.resize(k),B;
	}
	inline vector<int> Pow(vector<int> A,char *s,int k)
	{
		int t,b=0,b2=0,a,inv,l=strlen(s+1);
		LL tmp;
		for(int i=1;i<=l;++i)tmp=(LL)b*10+(s[i]^48),b=(tmp<mod? tmp:(tmp%mod)+mod),tmp=(LL)b2*10+(s[i]^48),b2=(tmp<mod-1? tmp:(tmp%(mod-1))+mod-1);
		for(t=0;t<A.size() && !A[t];++t);
		if(t==A.size() || (t && b2>A.size()/t))return A.resize(0),A.resize(k),A;
		inv=Pow(a=A[t],mod-2);
		for(int i=t;i<A.size();++i)A[i-t]=((LL)A[i]*inv)%mod;
		A.resize(A.size()-t),(A=Mul(Exp(A=Mul(Ln(A,k),b),k),Pow(a,b2))).resize(A.size()+(t*=b2));
		for(int i=A.size()-1;i>=t;--i)A[i]=A[i-t];
		for(int i=0;i<t;++i)A[i]=0;
		return A.resize(k),A;
	}
	inline vector<int> Pow(vector<int> A,LL s,int k)
	{
		int t,b=(s<mod? s:(s%mod)+mod),b2=(s<mod-1? s:(s%(mod-1))+mod-1),a,inv;
		for(t=0;t<A.size() && !A[t];++t);
		if(t==A.size() || (t && b2>A.size()/t))return A.resize(0),A.resize(k),A;
		inv=Pow(a=A[t],mod-2);
		for(int i=t;i<A.size();++i)A[i-t]=((LL)A[i]*inv)%mod;
		A.resize(A.size()-t),(A=Mul(Exp(A=Mul(Ln(A,k),b),k),Pow(a,b2))).resize(A.size()+(t*=b2));
		for(int i=A.size()-1;i>=t;--i)A[i]=A[i-t];
		for(int i=0;i<t;++i)A[i]=0;
		return A.resize(k),A;
	}
	inline void Rev(vector<int> &A)
	{
		for(int i=0;(i<<1)+1<A.size();++i)swap(A[i],A[A.size()-i-1]);
	}
	inline vector<int> Div(vector<int> A,vector<int> B)
	{
		int n=A.size(),m=B.size();
		return Rev(A),Rev(B),(A=Mul(A,Inv(B,n-m+1))).resize(n-m+1),Rev(A),A;
	}
	inline vector<int> Mod(vector<int> A,vector<int> B)
	{
		return (A=Add(A,Mul(Mul(B,Div(A,B)),-1))).resize(B.size()-1),A;
	}
	inline void Solve()
	{
		int n,k;
		vector<int> A,B,G,H,T;
		Init(),scanf("%d%d",&n,&k),++k,A.push_back(1),A.push_back(1),B.push_back(1),B.push_back(6),B.push_back(1),B=Sqrt(B,k),G=Add(A,Mul(B,-1)),G=Mul(G,_inv[2]),H=Add(A,B),H=Mul(H,_inv[2]),T=Mul(G,Inv(H,k)),A=Pow(T,n+1,k),add(A[0],mod-1),add(T[0],mod-1),A=Mul(Pow(H,n,k),Mul(A,Inv(T,k)));
		for(int i=1;i<k;++i)printf("%d ",A[i]);
	}
};
int main()
{
	Poly::Solve();
	return 0;
}