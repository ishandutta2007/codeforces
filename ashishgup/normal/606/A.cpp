#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int extra=0, reqd=0;
int a[5], b[5];

int32_t main()
{
	IOS;
	for(int i=1;i<=3;i++)
		cin>>a[i];
	for(int i=1;i<=3;i++)
		cin>>b[i];
	for(int i=1;i<=3;i++)
	{
		int cur=a[i], x=b[i];
		if(cur>=x)
			extra+=(cur-x)/2;
		else
			reqd+=x-cur;
	}
	if(extra>=reqd)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}