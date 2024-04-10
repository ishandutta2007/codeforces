//CF 981A
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
string s;
int n;
int chk(int l,int r){
	if(l>=r)
		return 1;
	if(s[l]==s[r])
		return chk(l+1,r-1);
	return 0;
}
int main()
{
	int i,j,ans=0;
	cin>>s;
	n=s.length();
	for(i=0;i<n;i=i+1)
		for(j=i;j<n;j=j+1)
			if(!chk(i,j))
				ans=max(ans,j-i+1);
	cout<<ans;
	return 0;
}