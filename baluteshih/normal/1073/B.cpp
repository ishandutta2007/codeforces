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

queue<int> st;
int vis[200001];

int main()
{jizz
	int n,x,cnt;
	cin >> n;
	for(int i=0;i<n;++i)
		cin >> x,st.push(x);
	for(int i=0;i<n;++i)
	{
		cin >> x,cnt=0;
		if(vis[x])
			cout << "0 ";
		else
		{
			while(st.front()!=x)
				vis[st.front()]=1,st.pop(),++cnt;
			vis[st.front()]=1,st.pop(),++cnt;
			cout << cnt << " ";
		}
	}
	ET;
}