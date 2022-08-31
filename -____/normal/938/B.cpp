//CF 938B
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
	int o=1e6,n,x,ans=0;
	cin>>n;
	while(n--){
		cin>>x;
		ans=max(ans,min(x-1,o-x));
	}
	cout<<ans;
	return 0;
}