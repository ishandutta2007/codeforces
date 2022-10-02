#include <bits/stdc++.h>
using namespace std;
int qzh[200005][20];
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for(int i=1;i<=200000;i++)
	{
		for(int j=0;j<20;j++)
		{
			if(i&(1<<j)) ++qzh[i][j];
			qzh[i][j]+=qzh[i-1][j];
		}
	}
	while(T--)
	{
		int l,r;
		cin >> l >> r;
		int ans=0;
		for(int i=0;i<20;i++)
			ans=max(ans,qzh[r][i]-qzh[l-1][i]);
		cout << r-l+1-ans << "\n";
	}
	return 0;
}