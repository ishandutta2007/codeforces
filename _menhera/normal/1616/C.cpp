#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--)
	{
		int N; cin >> N; vector<long long> V(N); for(auto&x: V) cin >> x;
		auto eq = [&](int s, int i, int e)
		{
			return (V[i]-V[s])*(e-s) == (V[e]-V[s])*(i-s);
		};
		int ans = N;
		if(N <= 2) ans = 0;
		for(int s=0; s<N; ++s)
		{
			for(int e=s+1; e<N; ++e)
			{
				int k = 0;
				for(int i=0; i<N; ++i) if(!eq(s, i, e)) ++k;
				// if(k == 1 || ans == 1) cout << s << " " << e << endl;
				ans = min(ans, k);
			}
		}
		cout << ans << '\n';
	}
}