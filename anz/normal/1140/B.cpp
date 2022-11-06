#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		char str[101];
		scanf("%d", &n);
		scanf("%s", str);

		if (str[0] == '<' && str[n - 1] == '>')
		{
			int minChunk = 987654321;
			int cnt = 1;
			for (int i = 1; i < n; i++)
				if (str[i] == '<')
					cnt++;
				else break;
			minChunk = min(minChunk, cnt);
			cnt = 1;
			for (int i = n - 2; i >= 0; i--)
				if (str[i] == '>')
					cnt++;
				else break;
			minChunk = min(minChunk, cnt);
			printf("%d\n", minChunk);
		}
		else
			printf("0\n");
	}
}