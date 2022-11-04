#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, q, ans = 0;

char ch1[41][3], ch2[41][3], Now[7];

vector <int> hsh[210];

map <ll, bool> S;

void Search(int x)
{
	if(x == n)
	{
		ll Val = 0;
		for(int i = 1; i <= 6; i++) Val = Val * 131 + Now[i] - 'a';
		if(S[Val] == 0) ans++, S[Val] = 1;
		return;
	}
	int tmp = Now[x];
	for(int i = 0; i < hsh[tmp].size(); i++)
	{
		Now[x] = ch1[hsh[tmp][i]][1], Now[x + 1] = ch1[hsh[tmp][i]][0];
		Search(x + 1);
		Now[x + 1] = 0, Now[x] = tmp;
	}
}
		
int main()
{
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= q; i++) scanf("%s%s", ch1[i], ch2[i]), hsh[ch2[i][0]].push_back(i);
	Now[1] = 'a';
	Search(1);
	printf("%d\n", ans);
	return 0;
}