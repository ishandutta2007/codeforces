#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define F first
#define S second
#define MP make_pair
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MOD=1e9+7,SQ=31624;

struct matrix{
	ll M[3][3],n,m;
	matrix(){}
	matrix(int n,int m):n(n),m(m){MEM(M,0);}
	matrix operator*(const matrix &a)const{
		matrix re(n,a.m);
		for(int i=0;i<re.n;++i)
			for(int j=0;j<re.m;++j)
				for(int k=0;k<m;++k)
					re.M[i][j]=(re.M[i][j]+M[i][k]*a.M[k][j])%(MOD-1);
		return re;
	}
}tmp,beg;

ll pw(ll a,ll n)
{
	ll re=1;
	for(;n;n>>=1,a=a*a%MOD)
		if(n&1) re=re*a%MOD;
	return re;
}

ll rv(ll x)
{
	map<ll,ll> mp;
	for(ll i=0,t=1;i<=SQ;++i,t=t*5%MOD)
		mp[t*x%MOD]=i;
	for(ll i=1,rt=pw(5,SQ),t=rt;i<=SQ;++i,t=t*rt%MOD)
	{
		auto p=mp.find(t);
		if(p!=mp.end())
			return i*SQ-p->S;
	}
	return 1;
}

int main()
{jizz
	ll n,f1,f2,f3,c,f4;
	cin >> n >> f1 >> f2 >> f3 >> c;
	f4=f1*f2%MOD*f3%MOD*pw(c,2)%MOD;
	f1=rv(f1*c%MOD),f2=rv(f2*pw(c,2)%MOD),f3=rv(f3*pw(c,3)%MOD);
	tmp=matrix(3,3),beg=matrix(1,3);
	tmp.M[0][0]=tmp.M[1][0]=tmp.M[2][0]=tmp.M[0][1]=tmp.M[1][2]=1;
	beg.M[0][0]=f3,beg.M[0][1]=f2,beg.M[0][2]=f1;
	for(ll x=n-3;x;x>>=1,tmp=tmp*tmp)
		if(x&1)
			beg=beg*tmp;
	cout << pw(5,beg.M[0][0])*pw(pw(c,n),MOD-2)%MOD << "\n";
}