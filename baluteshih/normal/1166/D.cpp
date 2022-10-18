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

ll arr[100],pls[100],tw[100];

int main()
{jizz
	ll q,a,b,m,s,t,ned;
	tw[0]=1;
	for(int i=1;i<=50;++i)
		tw[i]=1LL<<i-1;
	cin >> q;
	while(q--)
	{
		cin >> a >> b >> m,s=arr[0]=a;
		for(t=1;arr[t-1]<=b;++t)
			arr[t]=s+1,s+=arr[t],pls[t]=1;
		t-=2,ned=b-arr[t];
		for(int i=1;i<=t;++i)
			if(tw[t-i]<=ned)
			{
				if(ned/tw[t-i]<=m-1)
					pls[i]+=ned/tw[t-i],ned%=tw[t-i];
				else
					pls[i]+=m-1,ned-=tw[t-i]*(m-1);
			}
		if(ned!=0)
		{
			cout << "-1\n";
			continue;
		}
		cout << t+1 << " ",pls[0]=arr[0],s=0;
		for(int i=0;i<=t;++i)
			arr[i]=s+pls[i],s+=arr[i],cout << arr[i] << " \n"[i==t];
	}
}