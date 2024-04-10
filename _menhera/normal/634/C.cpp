#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 262144;
int n, k, a, b, q;
int arr[MAXN];
long long idx1[MAXN*2];
long long idx2[MAXN*2];
void update(long long idx[], int index, long long value)
{
	index += MAXN;
	idx[index] = value;
	while(index!=1)
	{
		index/=2;
		idx[index] = idx[index*2] + idx[index*2+1];
	}
	return;
}
long long getsum(long long idx[], int s, int e)
{
	s+=MAXN;
	e+=MAXN;
	long long ans = 0;
	while(s<=e)
	{
		if(s%2==1)
			ans+=idx[s++];
		if(e%2==0)
			ans+=idx[e--];
		s/=2;
		e/=2;
	}
	return ans;
}
int main()
{
	scanf("%d%d%d%d%d",&n,&k,&a,&b,&q);
	for(int i=0; i<q; i++)
	{
		int qq;
		scanf("%d",&qq);
		if(qq==1)
		{
			int di, ai;
			scanf("%d%d",&di,&ai);
			di--;
			arr[di]+=ai;
			update(idx1, di, min(b, arr[di]));
			update(idx2, di, min(a, arr[di]));
		}
		else
		{
			int pi;
			scanf("%d",&pi);
			pi--;
			//fix on[0, pi-1 ]; [pi+k, n-1]
			long long v = getsum(idx1, 0, pi-1) + getsum(idx2, pi+k, n-1);
			printf("%lld\n",v);
		}
	}
	return 0;
}