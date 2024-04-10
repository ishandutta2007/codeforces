#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e2 + 20;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int x , y , z , t1 , t2 , t3;
	cin >> x >> y >> z >> t1 >> t2 >> t3;

	int T1 = abs(x - y) * t1 , T2 = abs(x - z) * t2 + t3 * 2 + abs(x - y) * t2 + t3;

	if(T2 <= T1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}