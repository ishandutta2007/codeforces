#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int n,m,p[500005],e[500005];
inline int id(int x,int y,int d1,int d2)
{
	return ((x-1)*m+y)*4+(d1+2)/2+(d2+2)/2*2;
}
inline int ksm(int x,int y)
{
	int rtn=1;
	while(y)
	{
		if(y&1) rtn=rtn*x%mod;
		x=x*x%mod,y>>=1;
	}
	return rtn;
}
inline int inv(int x)
{
	return ksm(x,mod-2);
}
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		memset(p,0,sizeof p);
		memset(e,0,sizeof e);
		int a,b,c,d,P;
		cin >> n >> m >> a >> b >> c >> d >> P;
		P=P*inv(100)%mod;
		int dx=1,dy=1;
			if(a==n) dx=-1;
			if(a==1) dx=1;
			if(b==m) dy=-1;
			if(b==1) dy=1;
		p[id(a,b,dx,dy)]=1,e[id(a,b,dx,dy)]=0;
		if(a==c||b==d) p[id(a,b,dx,dy)]=p[id(a,b,dx,dy)]*(1-P+mod)%mod;
		int F=id(a,b,dx,dy);
		int cnt=0;
		for(int i=1;i<=n*m*4;i++)
		{
			++cnt;
			int qwqp=p[id(a,b,dx,dy)],qwqe=e[id(a,b,dx,dy)];
			if(a==n) dx=-1;
			if(a==1) dx=1;
			if(b==m) dy=-1;
			if(b==1) dy=1;
			a+=dx,b+=dy;
			if(a==n) dx=-1;
			if(a==1) dx=1;
			if(b==m) dy=-1;
			if(b==1) dy=1;
			p[id(a,b,dx,dy)]=qwqp;
			e[id(a,b,dx,dy)]=(qwqe+qwqp)%mod;
	//		cout << F << " " << a << " " << b << " " << dx << " " << dy << " " << id(a,b,dx,dy) << "\n";
			if(id(a,b,dx,dy)==F)
			{
				cout << inv(1-p[id(a,b,dx,dy)]+mod)*e[id(a,b,dx,dy)]%mod << "\n";
				break;
			}
			if(a==c||b==d) p[id(a,b,dx,dy)]=p[id(a,b,dx,dy)]*(1-P+mod)%mod;
		//	cout << (a==c||b==d) << " " << qwqp << "\n";
		}
	}
	return 0;
}