#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define pb push_back
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std; 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;

int num[200];

int main()
{jizz
	int n,i,j,k,ans=0;
	cin >> n;
	for(i=0;i<2*n;++i)
		cin >> num[i];
	for(i=0;i<2*n;i+=2)
		if(num[i+1]!=num[i])
			for(j=i+2;j<2*n;++j)
				if(num[j]==num[i])
				{
					for(k=j-1;k>i;--k)
						swap(num[k],num[k+1]),++ans;
					break;
				}
	cout << ans << "\n";
}