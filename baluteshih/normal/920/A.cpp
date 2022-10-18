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

int data[200];

int main()
{
	int t,n,k,ans,tmp;
	cin >> t;
	while(t--)
	{
		cin >> n >> k,ans=0;
		iop(i,0,k)
			cin >> data[i];
		iop(i,1,n+1)
		{
			tmp=n;
			iop(j,0,k)
				tmp=min(tmp,abs(data[j]-i)+1);
			ans=max(tmp,ans);
		}
		cout << ans << "\n";
	}
}