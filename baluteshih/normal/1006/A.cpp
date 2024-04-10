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

int main()
{jizz
	int n,x;
	cin >> n;
	while(n--)
		cin >> x,cout << (x-1)/2*2+1 << " ";
	ET;
}