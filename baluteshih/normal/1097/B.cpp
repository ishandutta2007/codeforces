#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int arr[20];

int main()
{jizz
	int n,flag=0,tmp;
	cin >> n;
	for(int i=0;i<n;++i)
		cin >> arr[i];
	for(int i=(1<<n)-1;i>=0;--i)
	{
		tmp=0;
		for(int j=0,x=i;j<n;++j,x>>=1)
			if(x&1)
				tmp+=arr[j];
			else 
				tmp-=arr[j];
		if(tmp%360==0) flag=1;
	}
	if(flag) cout << "YES\n";
	else cout << "NO\n";
}