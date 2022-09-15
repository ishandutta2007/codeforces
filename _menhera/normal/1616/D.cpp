#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--)
	{
		int N; cin >> N; vector<int> V(N); for(int&x: V) cin >> x;
		int x; cin >> x;
		if(N == 1) cout << 1 << '\n';
		else
		{
			vector<int> ss(N), s(N), n(N);
			s[1] = n[1] = 1;
			if(V[0] + V[1] >= 2*x) ss[1] = 2, s[1] = 1; else ss[1] = -N;
			for(int i=2; i<N; ++i)
			{
				n[i] = max({ss[i-1], s[i-1], n[i-1]});
				s[i] = n[i-1]+1;
				if(V[i] + V[i-1] >= 2*x)
				{
					ss[i] = max(ss[i], s[i-1]+1);
					if(V[i] + V[i-1] + V[i-2] >= 3*x)
						ss[i] = max(ss[i], ss[i-1]+1);
				}
			}
			cout << max({ss.back(), s.back(), n.back()}) << '\n';
		}
	}
}