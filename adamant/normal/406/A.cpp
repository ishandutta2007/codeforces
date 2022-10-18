#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main() 
{
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	int a[n][n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	int sq[n][2][2];
	int ans = 0;
	memset(sq, 0, sizeof(sq));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < 2; k++)
				for(int l = 0; l < 2; l++)
					if(i != j)
						sq[i][k][l] ^= (a[i][j] ^ k) & (a[j][i] ^ l);
					else
						sq[i][k][l] ^= (a[i][j] ^ k ^ l) & (a[j][i] ^ k ^ l);
						
	for(int i = 0; i < n; i++)
		ans ^= sq[i][0][0];
	int tp[n][2];
	memset(tp, 0, sizeof(tp));
	int q;
	cin >> q;
	int cnt = 0;
	while(q--)
	{
		int t;
		scanf("%d", &t);
		//cout << "! " << cnt << endl;
		if(t == 3)
		{
			if(ans ^ (cnt % 2))
				putchar('1');
			else
				putchar('0');
		}
		else 
		{
		scanf("%d", &t);
			cnt++;
		}
	}
}