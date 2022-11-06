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

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];

	if(a[0] != b[0])
		return cout << "No" << endl , 0;

	for(int i = 0; i + 1 < n; i++)
	{
		a[i] = a[i + 1] - a[i];
		b[i] = b[i + 1] - b[i];
	}

	sort(a , a + n - 1);
	sort(b , b + n - 1);

	for(int i = 0; i < n - 1; i++)
		if(a[i] != b[i])
			return cout << "No" << endl , 0;

	cout << "Yes" << endl;
}