#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;
const int M=3e6+5;

struct data
{
	int l;
	int r;
	int idx;
	long long store_ans;
};

int n, q, x, blocksz=1000;
int a[N], pref[N];
data queries[N];
long long freq[M];
long long ans=0;

bool comp(data &d1, data &d2)
{
	int blocka=d1.l/blocksz;
	int blockb=d2.l/blocksz;
	if(blocka<blockb)
		return true;
	else if(blocka==blockb)
		return (d1.r<d2.r)^(blocka%2);
	else  
		return false;
}

bool comp2(data &d1, data &d2)
{
	return d1.idx<d2.idx;
}

void update(long long k, int sign)
{
	if(sign==1)
	{
		ans+=freq[x^k];
		freq[k]++;
	}
	else
	{
		freq[k]--;
		ans-=freq[x^k];
	}
}

void calcmo()
{
	int moleft=1;
	int moright=0;
	for(int i=1;i<=q;i++)
	{
		int r=queries[i].r;
		int l=queries[i].l;
		while(moright<r)
		{
			moright++;
			update(pref[moright], 1);
		}
		while(moright>r)
		{
			update(pref[moright], -1);
			moright--;
		}
		while(moleft<l)
		{
			update(pref[moleft], -1);
			moleft++;
		}
		while(moleft>l)
		{
			moleft--;
			update(pref[moleft], 1);
		}
		queries[i].store_ans=ans;
	}
}

int main()
{
	IOS;
	cin>>n>>q>>x;
	memset(freq,0,sizeof(freq));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pref[i]=pref[i-1]^a[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>queries[i].l>>queries[i].r;
		queries[i].l--;
		queries[i].idx=i;
	}
	sort(queries+1, queries+q+1, comp);
	calcmo();
	sort(queries+1, queries+q+1, comp2);
	for(int i=1;i<=q;i++)
		cout<<queries[i].store_ans<<endl;
	return 0;	
}