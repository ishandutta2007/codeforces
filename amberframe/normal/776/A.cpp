#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <string>

using namespace std;
typedef long long LL;
const int maxn = 1005;

string a,b;
string u,v;int n;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("killer.in","r",stdin);
		freopen("killer.out","w",stdout);
	#endif
	cin>>u>>v>>n;
	cout<<u<<" "<<v<<endl;
	for (int i=1;i<=n;i++) {
		cin>>a>>b;
		if (a==u) u=b;
		else v=b;
		cout<<u<<" "<<v<<endl;
	}
	return 0;
}