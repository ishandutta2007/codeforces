#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while(T--)
	{
		int n;
		string s;
		cin >> n >> s;

		bool f = 1;
		for(int i = 0; i < n / 2; i++)
		{
			int A = s[i] , B = s[n - i - 1];
			if(A != B && A + 1 != B - 1 && A - 1 != B + 1)
				f = 0;
		}

		if(f)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

}