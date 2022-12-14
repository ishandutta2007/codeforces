#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int maxn = 1e3 + 100;
string s[maxn];
set <int> ss;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++){
		int dwr = -1;
		for (int j = 0; j < m; j++){
			if (s[i][j] == 'G')
				dwr = j;
			if (s[i][j] == 'S' and dwr == -1)
				return cout << -1 << endl, 0;
			else 
				if (s[i][j] == 'S')
					ss.insert (j - dwr);
		}
	}
	cout << ss.size() << endl;
}