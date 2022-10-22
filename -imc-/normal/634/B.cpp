#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll s, x;
	cin >> s >> x;
	
	ll d[60][2];
	memset(d, 0, sizeof(d));
	
	d[0][0] = 1;
	
	for (int length = 0; length + 1 < 60; length++)
		for (int carry = 0; carry < 2; carry++)
			for (int a = 0; a < 2; a++)
				for (int b = 0; b < 2; b++)
					if ((a ^ b) == ((x >> length) & 1) && (a + b + carry) % 2 == ((s >> length) & 1))
					{
						d[length + 1][(a + b + carry) / 2] += d[length][carry];
					}
					
	ll answer = d[59][0];
	if (s == x)
		answer -= 2;
	
	cout << answer << endl;
	
	return 0;
}