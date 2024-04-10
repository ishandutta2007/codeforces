#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define S second
#define F first
#define N (101*1000)
#define INF ((ll)3e18)

ll n,t,x[8],al,ar,bl,br,cl,cr,xl,xr;

pair<pair<bool,ll>,pair<ll,ll> > check(ll dis)
{
	xr=dis-x[0];xl=x[7]-dis;
	ar=dis-x[1];al=x[6]-dis;
	br=dis-x[2];bl=x[5]-dis;
	cr=dis-x[3];cl=x[4]-dis;
//	cout<<xl<<" "<<xr<<"\n"<<al<<" "<<ar<<"\n"<<bl<<" "<<br<<"\n"<<cl<<" "<<cr<<"\n";
	if(xl>xr || al>ar || bl>br || cl>cr)return {{0,0},{0,0}};
	for(int i=0;i<2;i++)
	{
		ll A=ar-(abs(ar)%2!=i),B=br-(abs(br)%2!=i),C=cr-(abs(cr)%2!=i);
		if(A<al || B<bl || C<cl)continue;
		if(A+B+C<=xr)
		{
			if(A+B+C>=xl)return {{1,(B+C)/2},{(A+C)/2,(A+B)/2}};
			continue;
		}
		ll ex=(A+B+C-xr+1)/2;
		ll p=min(A-al,ex*2)/2;A-=p*2;ex-=p;
		p=min(B-bl,ex*2)/2;B-=p*2;ex-=p;
		p=min(C-cl,ex*2)/2;C-=p*2;ex-=p;
		if(ex || A+B+C<xl)continue;
		return {{1,(B+C)/2},{(A+C)/2,(A+B)/2}};
	}
	return {{0,0},{0,0}};
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<8;i++)x[i]=-INF;
		for(int i=0;i<n;i++)
		{
			ll _x,y,z;
			cin>>_x>>y>>z;
			x[7]=max(x[7],_x+y+z);x[0]=max(x[0],-_x-y-z);
			x[6]=max(x[6],-_x+y+z);x[1]=max(x[1],_x-y-z);
			x[5]=max(x[5],_x-y+z);x[2]=max(x[2],-_x+y-z);
			x[4]=max(x[4],_x+y-z);x[3]=max(x[3],-_x-y+z);
		}
		ll l=-1,r=INF;
		while(l<r-1)
		{
			ll mid=(l+r)/2;
			if(check(mid).F.F)r=mid;
			else l=mid;
		}
		cout<<check(r).F.S<<" "<<check(r).S.F<<" "<<check(r).S.S<<"\n";
	}
	return 0;
}