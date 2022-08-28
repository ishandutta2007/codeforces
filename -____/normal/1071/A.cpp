//CF1071A
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
vector<int> v[2];
int main()
{
	int i,j;
	LL x,y,s;
	cin>>x>>y;
	s=0;
	for(i=1;s+i<=x+y;i=i+1)
		s+=i;
	for(j=i-1;j;j=j-1){
		if(x>=j)
			x-=j,v[0].push_back(j);
		else
			y-=j,v[1].push_back(j);
	}
	for(j=0;j<2;j=j+1){
		cout<<v[j].size();
		for(i=v[j].size();i--;)
			cout<<' '<<v[j][i];
		cout<<endl;
	}
	return 0;
}