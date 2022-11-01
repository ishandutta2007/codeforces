#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,h,m;
	cin >> n >> h >> m;
	vector<int> v(n+1,h);
	for(int o=0;o<m;o++)
    {
        int l,r,x;
        cin >> l >> r >> x;
        for(int i=l;i<=r;i++) v[i]=min(v[i],x);
    }
    int res=0;
    for(int i=1;i<=n;i++) res+=v[i]*v[i];
    cout << res << endl;
	return 0;
}