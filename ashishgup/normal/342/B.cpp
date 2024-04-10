#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n, m, s, f;
map<int, int> L, R;

int32_t main()
{
	IOS;
	cin>>n>>m>>s>>f;
	for(int i=1;i<=m;i++)
	{
		int t, l, r;
		cin>>t>>l>>r;
		L[t]=l;
		R[t]=r;
	}
	for(int i=1;;i++)
	{
		if(s==f)
			break;
		if(s<f)
		{
			if(s+1>=L[i]&&s<=R[i])
				cout<<"X";
			else
				cout<<"R", s++;
		}
		else
		{
			if(s>=L[i]&&s-1<=R[i])
				cout<<"X";
			else
				cout<<"L", s--;
		}
	}
	return 0;
}