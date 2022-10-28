#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

void print(char ch, int times)
{
	for(int i = 0; i < times; i++)
		cout << ch;
}

int32_t main()
{
	IOS;
	int k;
	cin >> k;
	vector<int> val(10, 1);
	int cur = 1, idx = 0;
	while(cur < k)
	{
		cur /= val[idx];
		val[idx]++;
		cur *= val[idx];
		idx = (idx + 1) % 10;
	}
	print('c', val[0]);
	print('o', val[1]);
	print('d', val[2]);
	print('e', val[3]);
	print('f', val[4]);
	print('o', val[5]);
	print('r', val[6]);
	print('c', val[7]);
	print('e', val[8]);
	print('s', val[9]);
	return 0;
}