#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	char guests[1000001];
	scanf("%s", guests);

	int startA[26];
	int endA[26];
	memset(startA, -1, sizeof(startA));
	memset(endA, -1, sizeof(endA));
	for (int i = 0; i < n; i++)
	{
		int gate = guests[i] - 'A';
		if (startA[gate] == -1) { startA[gate] = i; endA[gate] = i; }
		else endA[gate] = i;
	}
	bool answer = false;

	for (int i = 0; i < n; i++)
	{
		int num = 0;
		for (int j = 0; j < 26; j++)
		{
			if (startA[j] == -1) continue;
			if (startA[j] <= i && i <= endA[j]) num++;
		}
		if (num > k) { answer = true; break; }
	}

	if (answer) printf("YES");
	else printf("NO");
}