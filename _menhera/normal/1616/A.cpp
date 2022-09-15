#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--)
	{
		int N; vector<int> V(101);
		cin >> N;
		for(int i=0; i<N; ++i)
		{
			int t; cin >> t; V[abs(t)]++;
		}
		int ans = min(V[0], 1);
		for(int i=1; i<=100;++i) ans += min(V[i], 2);
		cout << ans << endl;
	}
}