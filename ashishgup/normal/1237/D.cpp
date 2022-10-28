#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 3e5 + 5;
const int LG = log2(N) + 1;

int n;
int a[N], r[N], floorlog[2 * N], ans[N];
int RMQ[LG][N];

void precompute()
{
	for(int i = 0; (1 << i) < N; i++)
	{
		for(int j = (1 <<i );j<N && j<(1<<(i+1)); j++)
			floorlog[j] = i;
	}

	for(int i = n;i >= 1; i--)
	{
		RMQ[0][i] = a[i]; 
		int mxj = floorlog[n-i+1]; //2^j <= n-i+1
		int pw = 1;
		for(int j = 1;j<=mxj;j++)
		{
			RMQ[j][i] = min(RMQ[j-1][i], RMQ[j-1][i+pw]);
			pw <<= 1;
		}
	}	
}

int getMin(int L, int R)
{
	int k = floorlog[R-L+1]; //2^k <= R-L+1
	return min(RMQ[k][L], RMQ[k][R - (1<<k) +1]);
}

int32_t main()
{
	IOS;
	cin >> n;
	vector<pair<int, int> > v;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i + n] = a[i];
		a[i + 2 * n] = a[i];
		v.push_back({a[i], i});
	}	
	stack<int> st;
	for(int i = 3 * n; i >= 1; i--)
	{
		while(st.size() && a[st.top()] < a[i])
			st.pop();
		r[i] = -1;
		if(st.size())
			r[i] = st.top();
 		st.push(i);
	}
	n *= 3;
	precompute();
	for(int i = n; i >= 1; i--)
	{
		int lo = i + 1, hi = n;
		while(lo < hi)
		{
			int mid = (lo + hi + 1) / 2;
			if(getMin(i + 1, mid) < (a[i] + 1)/ 2)
				hi = mid - 1;
			else
				lo = mid;
		}
		if(getMin(i + 1, lo) >= (a[i] + 1) / 2)
			lo++;
		if(r[i] == -1)
			ans[i] = lo;
		else
		{
			if(r[i] <= lo)
				ans[i] = ans[r[i]];
			else
				ans[i] = lo;
		}
	}
	for(int i = 1; i <= n / 3; i++)
	{
		ans[i] -= i;
		if(ans[i] > 2 * n / 3)
			ans[i] = -1;
		cout << ans[i] << " ";
	}
	return 0;
}