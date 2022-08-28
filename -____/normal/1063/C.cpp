//CF1063C
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
int q(int x,int y){
	string s;
	cout<<x<<' '<<y<<endl;
	cin>>s;
	return s[0]=='b';
}
int main()
{
	int n,i,l=0,r=1e9,m,t;
	cin>>n;
	t=q(0,1);
	for(i=1;i<n;i=i+1){
		m=l+r>>1;
		if(q(m,1)^t)
			r=m;
		else
			l=m;
	}
	cout<<l<<' '<<0<<' '<<r<<' '<<2<<endl;
	return 0;
}