#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll N =201*1000;

ll n,m,seg[4*N],lazy[4*N];

void shift(ll id)
{
	ll l=id*2,r=l+1;
	lazy[l]+=lazy[id];
	lazy[r]+=lazy[id];
	seg[l]+=lazy[id];
	seg[r]+=lazy[id];
	lazy[id]=0;
}

void update(ll ql,ll qr,ll xl,ll xr,ll id,ll add)
{
	if(qr<=xl || xr<=ql)return ;
	if(ql<=xl && xr<=qr)
	{
		lazy[id]+=add;
		seg[id]+=add;
		return ;
	}
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	shift(id);
	update(ql,qr,xl,mid,l,add);
	update(ql,qr,mid,xr,r,add);
	seg[id]=min(seg[l],seg[r]);
	//cout<<xl<<" "<<xr<<" "<<seg[id]<<"\n";
	//cout<<seg[id]<<" "<<seg[l]<<" "<<seg[r]<<"\n";
}

ll query(ll ql,ll qr,ll xl,ll xr,ll id)
{
	if(qr<=xl || xr<=ql)return INF;
	if(ql<=xl && xr<=qr)return seg[id];
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	shift(id);
	return min(query(ql,qr,xl,mid,l),query(ql,qr,mid,xr,r));
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   	cin>>n;
   	for(int i=0;i<n;i++)
	{
		ll ex;
		cin>>ex;
		update(i,i+1,0,N,1,ex);  	
	}
	cin>>m;
	cin.ignore();
	while(m--)
	{
		string str;
		getline(cin,str);
		ll i=0,l=0,r=0,neg=0;
		if(str[i]=='-')neg=1,i++;
		while('0'<=str[i] && str[i]<='9')l=l*10,l+=str[i]-'0',i++;
		if(neg)l=-l;
		
		neg=0;i++;
		if(str[i]=='-')neg=1,i++;
		while('0'<=str[i] && str[i]<='9' && i<str.size())r=r*10,r+=str[i]-'0',i++;
		if(neg)r=-r;
		
		if(i==str.size())
		{
			//cout<<"\\\\\\\\\\\ "<<l<<" "<<r<<"\n";
			if(l<=r)cout<<query(l,r+1,0,N,1)<<"\n";
			else cout<<min(query(l,n,0,N,1),query(0,r+1,0,N,1))<<"\n";
			continue;
		}
		ll num=0;
		neg=0;i++;
		if(str[i]=='-')neg=1,i++;
		while('0'<=str[i] && str[i]<='9' && i<str.size())num=num*10,num+=str[i]-'0',i++;
		if(neg)num=-num;
		if(l<=r)update(l,r+1,0,N,1,num);
		else update(l,n,0,N,1,num),update(0,r+1,0,N,1,num);
	}
	
	return 0;
}