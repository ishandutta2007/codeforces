#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
 
template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=1e5+5;
const int MM=1e5+5;
const int MOD=1e9+7;

int n, m, ct=1;
int st[21*N], lc[21*N], rc[21*N], root[21*N];


int build(int L, int R)
{
	int node=++ct;
	if(L==R)
	{
		return node;
	}
	int M=(L+R)>>1;
	lc[node]=build(L,M);
	rc[node]=build(M+1,R);
	return node;
}

int update(int onode, int L, int R, int pos, int val)
{
	int node=++ct;
	if(L==R)
	{	
		st[node]= val;
		return node;
	}
	int M=(L+R)>>1;
	lc[node]=lc[onode];
	rc[node]=rc[onode];
	if(pos<=M)
		lc[node]=update(lc[onode], L, M, pos, val);
	else
		rc[node]=update(rc[onode], M+1, R, pos, val);
	st[node]=max(st[lc[node]],st[rc[node]]);
	return node;
}

int query(int onode, int L, int R, int i, int j)
{
	if(j<L || i>R)
		return 0;
	if(i<=L && R<=j)
		return st[onode];
	int M=(L+R)>>1;
	int left=query(lc[onode], L, M, i, j);
	int right=query(rc[onode], M+1, R, i, j);
	return max(left, right);
}

int32_t main()
{
    IOS;
    cin>>n>>m;
    root[0]=build(1, MM);    for(int i=1;i<=m;i++)
    {
    	int u, v, w;
    	cin>>u>>v>>w;
    	w++;
    	int val=query(root[v], 1, MM, w, w);
    	val=max(val, 1+query(root[u], 1, MM, 1, w-1));
    	root[v]=update(root[v], 1, MM, w, val);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
    	ans=max(ans, query(root[i], 1, MM, 1, MM));
    }
    cout<<ans;
    return 0;
}