//CF 981C
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
const int N = 111111;
vector<int> v[N];
int n,s[N];
int main()
{
	int i,x,y;
	scanf("%d",&n);
	for(i=1;i<n;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
		s[x]++,s[y]++;
	}
	x=0,y=0;
	for(i=1;i<=n;i=i+1)
		if(s[i]>2)
			x++,y=i;
	if(x>1){
		cout<<"No";
		return 0;
	}
	cout<<"Yes"<<endl;
	if(x){
		x=0;
		for(i=1;i<=n;i=i+1)
			if(s[i]==1)
				x++;
		cout<<x<<endl;
		for(i=1;i<=n;i=i+1)
			if(s[i]==1)
				cout<<y<<' '<<i<<endl;
		return 0;
	}
	for(i=1;i<=n;i=i+1)
		if(s[i]==1){
			if(!x)
				x=i;
			else
				y=i;
		}
	cout<<1<<endl<<x<<' '<<y<<endl;
	return 0;
}