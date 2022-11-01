#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << 4*(n-1)+1+max(0,2*(n-2)*(n-1)) << endl;
	return 0;
}