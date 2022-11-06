#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a , b , c;
	cin >> a >> b >> c;

	int res = 0;
	for(int i = 1; i <= a; i++)
		for(int j = i + 1; j <= i + 1 && j <= b; j++)
			for(int k = j + 1; k <= j + 1 && k <= c; k++)
				res = max(res , i + j + k);

	cout << res << endl;
}