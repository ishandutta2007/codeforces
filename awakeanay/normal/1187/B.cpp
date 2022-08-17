#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	int m;
	std::cin >> m;

	int det[26][n];
	int count[26];

	for(int i = 0; i < 26; i++)
	{
		count[i] = 0;
		det[i][0] = 0;
	}

	for(int i = 0; i < n; i++)
	{
		int c = s[i] - 'a';
		count[c]++;
		det[c][count[c]] = i;
	}

	while(m--)
	{
		std::string t;
		std::cin >> t;

		int k = t.length();

		int rem[26];
		for(int i = 0; i < 26; i++)
			rem[i] = 0;

		for(int i = 0; i < k; i++)
			rem[t[i] - 'a']++;

		int answer = 0;
		for(int i = 0; i < 26; i++)
		{
			answer = std::max(answer, det[i][rem[i]]);
		}

		std::cout << answer+1 << std::endl;
	}
}