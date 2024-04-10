#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

pii num[2000];
bitset<2000> vis;
int pri[2001];

bool yee(pii a,pii b)
{
	return a.S<b.S;
}

int main()
{jizz
	int n,k,cnt,ans=0,i;
	cin >> n >> k;
	for(i=0;i<n;++i)
		cin >> num[i].F,num[i].S=i;
	sort(num,num+n);
	for(i=n-1;i>=n-k;--i)
		vis[num[i].S]=1,ans+=num[i].F;
	sort(num,num+n,yee);
	cout << ans << "\n";
	for(i=0,cnt=vis[0];i<n;++i,cnt+=vis[i])
		++pri[cnt];
	for(pri[1]+=pri[0],i=1;i<=k;++i)
		cout << pri[i] << " ";
	ET;
}