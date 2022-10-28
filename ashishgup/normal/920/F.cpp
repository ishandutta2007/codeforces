#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int a[N], d[N], st[4*N];

void build(int node, int L, int R)
{
	if(L==R)
	{
		st[node]=a[L];
		return;
	}
	int M=(L+R)>>1;
	build(node*2, L, M);
	build(node*2 + 1, M+1, R);
	st[node]=st[node*2]+st[node*2+1];
}

int query(int node, int L, int R, int i, int j)
{
	if(j<L || i>R)
		return 0;
	if(i<=L && R<=j)
		return st[node];
	int M=(L+R)>>1;
	int left=query(node*2, L, M, i, j);
	int right=query(node*2 + 1, M+1, R, i, j);
	return left+right;
}

void update(int node, int L, int R, int pos, int val)
{
	if(L==R)
	{
		st[node]=val;
		return;
	}
	int M=(L+R)>>1;
	if(pos<=M)
		update(node*2, L, M, pos, val);
	else
		update(node*2 + 1, M+1, R, pos, val);
	st[node]=st[node*2]+st[node*2+1];
}

int32_t main()
{
    IOS;
    int n, m;
    cin>>n>>m;
    for(int i=1;i<N;i++)
    {
    	for(int j=1;i*j<N;j++)
    	{
    		d[i*j]++;
    	}
    }
    set<int> active;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	active.insert(i);
    }
    build(1, 1, n);
    for(int i=1;i<=m;i++)
    {
    	int type;
    	cin>>type;
    	if(type==1)
    	{
    		int l, r;
    		cin>>l>>r;
    		auto ind=active.lower_bound(l);
    		vector<int> to_del;
    		while(ind!=active.end() && (*ind<=r))
    		{
    			if(d[a[*ind]]==a[*ind])
    			{
    				to_del.push_back(*ind);
    			}
    			else
    			{
    				update(1, 1, n, *ind, d[a[*ind]]);
    				a[*ind]=d[a[*ind]];
    			}
    			ind++;
    		}
    		for(auto it:to_del)
    		{
    			active.erase(it);
    		}
    	}
    	else
    	{
    		int l, r;
    		cin>>l>>r;
    		int ans=query(1, 1, n, l, r);
    		cout<<ans<<endl;
    	}
    }
    return 0;
}