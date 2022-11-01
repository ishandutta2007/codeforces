#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(101,0);
	int res=0;
	for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;
        res=max(res,++v[t]);
    }
    cout << res << endl;
	return 0;
}