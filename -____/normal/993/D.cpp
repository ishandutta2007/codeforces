//CF 993D
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
const int N = 55;
const int M = 5555;
const LL INF = 1e15;
void cmin(LL& x,LL y){
	if(x>y)
		x=y;
}
int n;
pair<int,int> a[N];
LL f[2][N][M],s,ans;
vector<int> v;
LL sv[N];
int main()
{
	int i,j,l,k,x,y,o,t;
	cin>>n;
	for(i=1;i<=n;i=i+1){
		cin>>x;
		a[i].first=x;
	}
	for(i=1;i<=n;i=i+1){
		cin>>x;
		a[i].second=x;
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	f[0][0][0]=-INF;
	o=0;
	for(i=1;i<=n;){
		v.clear();
		v.push_back(0);
		t=0;
		x=a[i].first;
		while(a[i].first==x){
			v.push_back(a[i].second);
			i++;
			t++;
		}
		for(l=1;l<=t;l=l+1)
			sv[l]=sv[l-1]+v[l];
		for(l=0;l<=t;l=l+1){
			for(j=t-l;j-(t-l)+l<=n&&j<=n;j=j+1)
				for(k=0;k+sv[l]<=5000;k=k+1)
					cmin(f[o^1][j-(t-l)+l][k+sv[l]],f[o][j][k]+(LL)l*x);
		}
		for(j=0;j<=n;j=j+1)
			for(k=0;k<=5000;k=k+1)
				f[o][j][k]=0;
		o^=1;
	}
	ans=INF;
	for(k=1;k<=5000;k=k+1){
		s=0;
		for(j=0;j<=n;j=j+1)
			cmin(s,f[o][j][k]);
		s+=INF;
		//if(s<1e9)
		//cout<<k<<' '<<s<<endl;
		s*=1000;
		if(s%k)	
			s=s/k+1;
		else
			s=s/k;
		cmin(ans,s);
	}
	cout<<ans;
	return 0;
}