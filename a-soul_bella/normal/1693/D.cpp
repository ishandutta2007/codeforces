#include <bits/stdc++.h>
#define int long long
using namespace std;
int p[200005],C;
const int inf=1e6;
inline bool cmp(pair<int,int> x,pair<int,int> y)
{
	return x.first-x.second<y.first-y.second;
}
//unordered_map <int,int> mp;
const int X1=1e12,X2=1e6,mod=1e6+7,XOR=123456789;
struct hashmap{
	int head[mod],nx[mod],X[mod],Y[mod],nw;
	inline void ins(int x,int y)
	{
		if(x<0) x=-x;
		x^=XOR;
		nx[++nw]=head[x%mod];
		head[x%mod]=nw;
		X[nw]=x,Y[nw]=y;
	}
	inline int ask(int x)
	{
		if(x<0) x=-x;
		x^=XOR;
		for(int i=head[x%mod];i;i=nx[i])
			if(X[i]==x) return Y[i];
		return 0;
	}
}mp;
inline int geth(pair<int,int> A,pair<int,int> B,int k)
{
	if(A>B) swap(A,B);
	return A.first*X1+A.second*X2+B.second+k*22632424;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> p[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		pair <int,int> A={-inf,inf},B={-inf,inf};
		int cnt=0;
		vector <int> v;
		int R=i-1;
		for(int j=i;j<=n;j++)
		{
			if(mp.ask(geth(A,B,j)))
			{
				R=mp.ask(geth(A,B,j));
				ans+=R-j+1;
				break;
			}
			else v.push_back(geth(A,B,j));
			pair <int,int> na={p[j],A.second},nb={A.first,p[j]},nc={p[j],B.second},nd={B.first,p[j]};
			if(na.first<=A.first) na={inf,-inf};
			if(nb.second>=A.second) nb={inf,-inf};
			if(nc.first<=B.first) nc={inf,-inf};
			if(nd.second>=B.second) nd={inf,-inf};
			if(cmp(na,nc)) A=na;
			else A=nc;
			if(cmp(nb,nd)) B=nb;
			else B=nd;
			if(A.first==inf&&B.first==inf)
				break;
			R=j;
//			cout << B.first << " " << B.second << " " << A.first << " " << A.second << "*\n";
			++ans;
		}
		for(auto t:v) mp.ins(t,R);
	}
	cout << ans;
	return 0;
}