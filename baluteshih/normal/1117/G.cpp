#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MAXN=1000005,INF=1e9;
struct mode
{
	ll F,S,i;
}query[MAXN];
ll num[MAXN],lf[MAXN],rg[MAXN],ans[MAXN];
ll bit[2][MAXN],n,flag;
stack<ll> st;

bool cmp1(mode a,mode b)
{
	return a.S<b.S;
}

bool cmp2(mode a,mode b)
{
	return a.F>b.F;
}

void modify(ll x,ll v,ll t)
{
	if(flag==1) x=n-x+1;
	for(;x<=n;x+=x&-x) bit[t][x]+=v;
}

ll Query(ll x,ll t)
{
	ll re=0;
	if(flag==1) x=n-x+1;
	for(;x;x-=x&-x) re+=bit[t][x];
	return re;
}

int main()
{jizz
	ll q,t;
	cin >> n >> q,num[0]=num[n+1]=INF;
	for(int i=1;i<=n;++i)
		cin >> num[i];
	for(int i=1;i<=q;++i)
		cin >> query[i].F,query[i].i=i;
	for(int i=1;i<=q;++i)
		cin >> query[i].S,ans[i]+=query[i].S-query[i].F+1;
		
	sort(query+1,query+q+1,cmp1),st.push(0),t=1;
	for(int i=1;i<=n;++i)
	{
		while(num[i]>num[st.top()]) st.pop();
		lf[i]=st.top(),st.push(i);
		if(lf[i]) modify(1,i-lf[i]-1,0),modify(lf[i]+1,-(i-lf[i]-1),0);
		modify(lf[i]+1,i,0),modify(i+1,-i,0),modify(lf[i]+1,1,1),modify(i+1,-1,1);
		while(t<=q&&query[t].S<=i) 
			ans[query[t].i]+=Query(query[t].F,0)-Query(query[t].F,1)*query[t].F,++t;
	}
	
	while(!st.empty()) st.pop();
	MEM(bit,0),sort(query+1,query+q+1,cmp2),st.push(n+1),t=1,flag=1;
	for(int i=n;i>0;--i)
	{
		while(num[i]>num[st.top()]) st.pop();
		rg[i]=st.top(),st.push(i);
		if(rg[i]<=n) modify(n,rg[i]-i-1,0),modify(rg[i]-1,-(rg[i]-i-1),0);
		modify(rg[i]-1,-i,0),modify(i-1,i,0),modify(rg[i]-1,1,1),modify(i-1,-1,1);
		while(t<=q&&query[t].F>=i) 
			ans[query[t].i]+=Query(query[t].S,0)+Query(query[t].S,1)*query[t].S,++t;
	}

	for(int i=1;i<=q;++i)
		cout << ans[i] << " \n"[i==q];
}