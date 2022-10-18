#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define pb push_back
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

priority_queue<int> pq;
bitset<10005> vis;

int main()
{jizz
	int n,x,a;
	cin >> n;
	while(n--)
		cin >> x,pq.push(x);
	a=pq.top(),pq.pop(),vis[a]=1;
	while(a%pq.top()==0&&!vis[pq.top()])
		vis[pq.top()]=1,pq.pop();
	cout << a << " " << pq.top() << "\n";
}