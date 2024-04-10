#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cerr << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

char aph[5]={ 'a', 'e', 'i', 'o','u'};

int main()
{jizz
	int k;
	cin >> k;
	for(int i=5;i*5<=k;++i)
		if(k%i==0)
		{
			int n=i,m=k/i;
			vector<string> v(n,string(m,'x'));
			for(int j=0;j<n;++j)
				for(int t=0;t<m;++t)
					v[j][t]=aph[(j+t)%5];
			for(int j=0;j<n;++j)
				cout << v[j];
			ET;
			return 0;
		}
	cout << "-1\n";
}