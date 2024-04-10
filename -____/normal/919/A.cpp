//CF 919A
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
int main()
{
	int n,m,a,b;
	DB ans;
	cin>>n>>m;
	ans=1e18;
	while(n--){
		cin>>a>>b;
		ans=min(ans,(DB)a/b);
	}
	printf("%.9f",ans*m);
	return 0;
}