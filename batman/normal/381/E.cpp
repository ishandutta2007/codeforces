#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N ((ll)3001*1000)
string s;
ll q,seg[N],le[N],ri[N];

void build(ll id,ll b,ll e)
{
	//cout<<id<<" "<<b<<" "<<e<<"\n";
	if(b==e)
	{
		if(s[b]=='(')
			le[id]=1;
		else
			ri[id]=1;
			
		return ;
	}
	ll l=id<<1,r=l|1,mid=e+b>>1;
	build(l,b,mid),build(r,mid+1,e);
	ll ex=min(le[l],ri[r]);
	
	seg[id]=seg[l]+seg[r]+ex*2;
	le[id]=le[l]+le[r]-ex;
	ri[id]=ri[l]+ri[r]-ex;
	//cerr<<id<<" "<<b<<" "<<e<<"\n";
	return ;
}

ll query(ll id,ll left,ll right,ll b,ll e,ll &left_,ll &right_)
{
	
	if(left>e || right<b)
		return 0;
	//cout<<id<<" "<<seg[id]<<" "<<left<<" "<<right<<" "<<b<<" "<<e<<"\n";	
	if(left==b && right==e)
	{
		left_=le[id],right_=ri[id];
		return seg[id];
	}
		
	ll l=id<<1,r=l|1,mid=b+e>>1;
	ll left2_=0,left3_=0,right2_=0,right3_=0;
	
	ll ans=query(l,left,min(right,mid),b,mid,left2_,right2_),ans2=query(r,max(mid+1,left),right,mid+1,e,left3_,right3_);
	ll x=min(left2_,right3_);
	ll ans3=ans+ans2+x*2;
	left_=left2_+left3_-x;
	right_=right2_+right3_-x;
	return ans3;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>s>>q;
	build(1,0,s.size()-1);
	//cout<<le[16]<<" "<<ri[17]<<endl;
	//cerr<<"hir";
	while(q--)
	{
		ll l,r,left_=0,right_=0;
		cin>>l>>r;
		l--,r--;
		cout<<query(1,l,r,0,s.size()-1,left_,right_)<<"\n";
	}
	return 0;
}