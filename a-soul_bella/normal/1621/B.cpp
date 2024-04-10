#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int mnp=1e18,mxp=0,L=0,R=0,LR=0;
		for(int i=1;i<=n;i++)
		{
			int l,r,c;
			cin >> l >> r >> c;
			if(l<mnp) L=c,LR=1e18;
			if(r>mxp) R=c,LR=1e18;
			mnp=min(mnp,l),mxp=max(mxp,r);
			if(l==mnp&&r==mxp) LR=min(LR,c);
			if(l==mnp) L=min(L,c);
			if(r==mxp) R=min(R,c);
			cout << min(L+R,LR) << "\n";
		}
	}
	return 0;
}