#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int a[maxn] , b[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , s;
	cin >> n >> s;
	s--;

	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];

	bool f = a[s];
	for(int i = s + 1; i < n; i++)
		if(a[i] && b[i] && b[s])
			f |= 1;

	f &= a[0];

	if(f)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}