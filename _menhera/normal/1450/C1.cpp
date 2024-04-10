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
		int N; cin >> N;
		vector<string> V;
		for(int i=0; i<N; ++i)
		{
			string s; cin >> s; V.push_back(s);
		}
		vector<int> cnt(3);
		for(int i=0; i<N; ++i)
		{
			for(int j=0; j<N; ++j)
			{
				int t = (i+j)%3;
				if(V[i][j] == 'X') ++cnt[t];
			}
		}
		int idx = min_element(cnt.begin(), cnt.end())-cnt.begin();
		for(int i=0; i<N; ++i)
		{
			for(int j=0; j<N; ++j)
			{
				int t = (i+j)%3;
				if(V[i][j] == 'X' && t == idx) cout << 'O';
				else cout << V[i][j];
			}
			cout << endl;
		}
	}
}