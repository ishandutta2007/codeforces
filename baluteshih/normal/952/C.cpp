#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll int64_t
#define pb push_back
#define MEM(i,j) memset(i,j,sizeof i)
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;

int num[150];

int main()
{
	int n,i,j,ma,man;
	cin >> n;
	for(i=0;i<n;++i)
		cin >> num[i];
	while(n)
	{
		for(j=0;j<n-1;++j)
			if(abs(num[j]-num[j+1])>1)
				return cout << "NO\n",0;
		for(j=0,ma=0;j<n;++j)
			if(num[j]>ma) man=j,ma=num[j];
		for(j=man;j<n-1;++j)
			num[j]=num[j+1];
		n--;
	}
	cout << "YES\n";
}