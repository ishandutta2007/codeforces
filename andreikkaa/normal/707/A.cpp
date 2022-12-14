#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < n * m; ++i)
	{
		char c;
		cin >> c;
		if(c != 'G' and c != 'B' and c != 'W')
		{
			cout << "#Color" << endl;
			return 0;
		}
	}
	cout << "#Black&White" << endl;
	
	return 0;
}