#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int a[1000005];
char op[1000005];
vector<int> p,s[100],ss[100];
int in[100],m,ans=0,sum[100];
int n,B,P,M,ppp=1,NN;
void dfs(int nw)
{
	if(nw==m)
	{
		int b=B;
		for(int i=0;i<m;i++)
			if(in[i]) b-=M;
		if(b<0) return ;
		b/=P;
		b=min(b,NN);
/*		for(int i=0;i<m;i++)
		{
			if(in[i])
			{
				cout << p[i] << "!";
			}
		}
		cout << b << "**\n";*/
		vector<int> v;
		int nw=1,S=0;
		for(int i=0;i<=m;i++)
		{
			S+=ppp/nw*sum[i];
			if(i<m&&!in[i]) nw*=p[i];
		}
		int s2=0;
		int L=0,R=4.5e18,pos=0;
		while(L<=R)
		{
			int mid=(L+R)/2;
			int CNT=0,SS=0;
			nw=1;
			for(int i=0;i<=m;i++)
			{
				int xx=ppp-(ppp/nw);
				int ll=0,rr=(int)s[i].size()-1,POS=-1;
				while(ll<=rr)
				{
					int M=(ll+rr)/2;
					if(xx*s[i][M]>=mid) POS=M,ll=M+1;
					else rr=M-1;
				}
//				for(auto t:s[i])
//					if(xx*t>=mid) ++CNT,SS+=xx*t;
				CNT+=POS+1;
				if(i<m&&!in[i]) nw*=p[i];
			}
	//		cout << mid << " " << b << " " << CNT << "\n";
		//	cout << CNT << " " << b << "**\n";
			if(CNT>=b)
				L=mid+1,pos=mid;
			else R=mid-1;
		}
		nw=1;
		int CNT=0,SS=0;
		for(int i=0;i<=m;i++)
		{
			int xx=ppp-(ppp/nw);
			int ll=0,rr=(int)s[i].size()-1,POS=-1;
			while(ll<=rr)
			{
				int M=(ll+rr)/2;
				if(xx*s[i][M]>=pos) POS=M,ll=M+1;
				else rr=M-1;
			}
		/*	if(b==100000)
			{
			cout << xx << "??????\n";
				if(POS>=0) cout << s[i][POS]*xx << "qwq\n";
				cout << pos << " " << s[i].size() << " " << POS << "!!\n";
			}*/
//				for(auto t:s[i])
//					if(xx*t>=mid) ++CNT,SS+=xx*t;
			CNT+=POS+1;
			if(POS>=0) SS+=ss[i][POS]*xx;
			if(i<m&&!in[i]) nw*=p[i];
		}
//		cout << b << " " << pos << " " << CNT << " " << SS << " " << S << "*\n";
		s2=SS-(CNT-b)*pos; 
	//	sort(v.begin(),v.end());
	//	reverse(v.begin(),v.end());
	//	for(int i=0;i<b;i++) s2+=v[i];
//		cout << S << "!!!\n";
		ans=max(ans,S+s2);
		return ;
	}
	int flag=1;
	for(int i=0;i<nw;i++)
	{
		if(p[nw]==p[i]&&!in[i])
		{
			flag=0;
			break;
		}
	}
	if(flag)
	{
		in[nw]=1;
		dfs(nw+1);
	}
	in[nw]=0;
	dfs(nw+1);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> B >> P >> M;
	for(int i=1;i<=n;i++)
	{
		cin >> op[i] >> a[i];
		if(op[i]=='*'&&a[i]==1)
			--n,--i;
	}
	for(int i=1;i<=n;i++)
	{
		if(op[i]=='+') s[p.size()].push_back(a[i]),++NN;
		if(op[i]=='*') p.push_back(a[i]),ppp*=a[i];
	}
	m=p.size();
	for(int i=0;i<=m;i++)
	{
		sort(s[i].begin(),s[i].end());
		reverse(s[i].begin(),s[i].end());
		ss[i].resize(s[i].size());
		if(s[i].size()) ss[i][0]=s[i][0];
		for(int j=1;j<s[i].size();j++)
			ss[i][j]=ss[i][j-1]+s[i][j];
		for(auto t:s[i]) sum[i]+=t;
	}
	dfs(0);
	cout << ans+ppp;
	return 0;
}
/*
8 100000 1 100000
* 2
+ 1
* 4
+ 1
+ 1
+ 1
* 5
+ 3

*/