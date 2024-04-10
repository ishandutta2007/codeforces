#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned long long
#define db long double
#define pii pair<ll,int>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define lb lower_bound
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define per(i,b,a) for(register int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(register int i=(a);i<(b);++i)
#define fore(i,a) for(register int i=0;i<a.size();++i)
#define ls x<<1,l,m
#define rs x<<1|1,m+1,r
#define gc() getchar()
inline int rd()
{
	int x=0,w=1;char c=gc();while(!isdigit(c)&&c!='-')c=gc();
	if(c=='-')w=-1,c=gc();while(isdigit(c))x=x*10+c-48,c=gc();return x*w;
}
const int N=100005;
int n,a[N],b[N],c[N];
set<int>S;priority_queue<int>Q,Q2;
void sol()
{
	n=rd();S.clear();
	while(!Q.empty())Q.pop();
	while(!Q2.empty())Q2.pop();
	rep(i,1,n)a[i]=rd(),b[a[i]]=i,c[i]=1;
	rep(i,1,n)Q.push(1),S.insert(i);
	rep(i,1,n)
	{
		int t=c[b[i]];
		while(!Q2.empty()&&Q.top()==Q2.top())Q.pop(),Q2.pop();
		if(Q.top()!=t){puts("No");return;}
		Q.pop();
		set<int>::iterator it=S.lower_bound(b[i]);
		it++;
		if(it!=S.end())
		{
			int p=*it;Q2.push(c[p]);
			c[p]+=t;Q.push(c[p]); 
		}
		S.erase(b[i]);
	} 
	puts("Yes");
}
int main(){int T=rd();while(T--)sol();return 0;}