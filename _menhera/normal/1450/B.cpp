#include<bits/stdc++.h>
using namespace std;
int x[101010], y[101010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while(T--)
	{
		int N, K; cin >> N >> K;
		for(int i=0; i<N; ++i) cin >> x[i] >> y[i];
		int ans = -1;
		for(int i=0; i<N; ++i)
		{
			bool flag = true;
			for(int j=0; j<N; ++j)
			{
				int d = abs(x[i]-x[j])+abs(y[i]-y[j]);
				if(d > K) flag = false;
			}
			if(flag) ans = 1;
		}
		cout << ans << endl;
	}
}