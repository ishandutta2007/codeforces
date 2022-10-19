///
///   kono giorno giovanna niwa yume ga aru
///
 
#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
 
typedef int ymm __attribute((vector_size(32),aligned(4)));
 
const int N = 250106;;
const int S1 = 20480;
const int S2 = 40960;
 
int m[N], tmp[S2], a[N];
int n;
 
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int al = 0; al < n; al += S1)
	{
		int ar = min(al+S1, n);
		memset(tmp, 0, sizeof tmp);
		for(int ml = 0; ml < ar; ml += S2)
		{
			int mr = ml+S2;
			for(int i = al; i < ar; ++i)
			{
				int ttmp = tmp[i-al];
				tmp[i-al] = m[mr];
				int zz = 0;
				if(a[i] <= i+1)
				{
					if(ml+2 <= a[i] && a[i] < mr+1)
						zz = max(m[a[i]], m[a[i]-1]+1);
					if(ml+1 == a[i])
						zz = max(m[a[i]], ttmp+1);
				}
				for(int j = mr-8; j > ml; j -= 8)
				{
					*(ymm*)(m+j+1) = *(ymm*)(m+j+1) > *(ymm*)(m+j)? *(ymm*)(m+j+1): *(ymm*)(m+j);
				}
				for(int j = ml+7; j > ml; j--)
					m[j+1] = max(m[j+1], m[j]);
				m[ml+1] = max(m[ml+1], ttmp);
				if(a[i] <= i+1) m[a[i]] = max(m[a[i]], zz);
			}
		}
	}
	int ans = 0;
	for(int i=0;i<N;++i) ans = max(ans, m[i]);
	cout << ans << '\n';
	//cout << double(clock())/CLOCKS_PER_SEC << '\n';
}