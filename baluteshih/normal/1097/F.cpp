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

const int MAXC=7000;
bitset<MAXC+1> ms[100005],org[MAXC+1],ans[MAXC+1],sq;

int main()
{jizz
	int n,q,k,x,y,z,v;
	for(int i=MAXC;i>=1;ans[i][i]=1,--i)
		for(int j=i;j<=MAXC;j+=i)
			ans[i]^=ans[j],org[j][i]=1;
	cin >> n >> q;
	while(q--)
	{
		cin >> k;
		if(k==1)
			cin >> x >> v,ms[x]=org[v];
		else if(k==2)
			cin >> x >> y >> z,ms[x]=ms[y]^ms[z];
		else if(k==3)
			cin >> x >> y >> z,ms[x]=ms[y]&ms[z];
		else 
			cin >> x >> v,cout << (ms[x]&ans[v]).count()%2;
	}
	ET;
}