#pragma GCC optimize ("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <bitset>
#include <queue>
#include <map> 
#include <math.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define ll long long
#define iop(i,a,n) for(int i=a;i<n;i++)
using namespace std;

int l[1000],r[1000],ans[1000];

int main()
{
	int t,n,times;
	cin >> t;
	while(t--)
	{
		cin >> n,times=1;
		iop(i,0,n)
		{
			cin >> l[i] >> r[i];
			while(times<l[i]) times++;
			if(times>r[i]) ans[i]=0;
			else ans[i]=times++;
		}
		iop(i,0,n)
			if(!i) cout << ans[i];
			else cout << " " << ans[i];
		cout << "\n";
	}
}