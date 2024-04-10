#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pb push_back
#define MEM(i,j) memset(i,j,sizeof i)
#define F first
#define S second
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;

int num[100][100];

int main()
{
	int n,m,d,i,j,a,b,tmp,ans=1000000000;
	cin >> n >> m >> d;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			cin >> num[i][j];
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			tmp=0;
			for(a=0;a<n;a++)
				for(b=0;b<m;b++)
					if(num[i][j]%d!=num[a][b]%d)
						return cout << "-1\n",0;
					else tmp+=abs(num[i][j]-num[a][b])/d;
			ans=min(tmp,ans);
		}
	cout << ans << "\n";
}