#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m,r;
	cin >> n >> m >> r;
	int a=1000,b=0;
	int temp;
	for(int i=0;i<n;i++)
    {
        cin >> temp;
        a=min(a,temp);
    }
    for(int i=0;i<m;i++)
    {
        cin >> temp;
        b=max(b,temp);
    }
    cout << max((r/a)*b+r-(r/a)*a,r) << endl;
	return 0;
}