#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	string commands;
	cin >> commands;
	
	vector<pair<int, int>> psum(n + 1);
	for (int i = 0; i <= n; i++)
	{
		if (i != 0)
		{
			psum[i] = psum[i - 1];
			psum[i].first += (commands[i - 1] == 'L' ? -1 : (commands[i - 1] == 'R' ? 1 : 0));
			psum[i].second += (commands[i - 1] == 'U' ? -1 : (commands[i - 1] == 'D' ? 1 : 0));
		}
	}
	
	int answer = 0;
	for (int i = 0; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (psum[i] == psum[j])
				answer++;
			
	printf("%d\n", answer);
	
	return 0;
}