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
		cout << 1;
	cout << endl;

	for(int i = 0; i < n - 1; i++)
		cout << 8;
	cout << 9 << endl;
}