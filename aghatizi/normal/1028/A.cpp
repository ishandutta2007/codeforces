#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e2 + 20;

string s[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;

	for(int i = 0; i < n; i++)
		cin >> s[i];

	pair<int , int> mn = {n , m} , mx = {-1 , -1};

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(s[i][j] == 'B')
			{
				mn = min(mn , make_pair(i , j));
				mx = max(mx , make_pair(i , j));
			}
	cout << (mn.first + mx.first) / 2 + 1 << " " << (mn.second + mx.second) / 2 + 1 << endl;

}