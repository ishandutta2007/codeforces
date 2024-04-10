//CF 966C
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
const int N = 111111;
int n;
LL a[N];
vector<LL> v[66];
int main()
{
	int i,j,k,s;
	cin>>n;
	for(i=0;i<n;i=i+1)
		cin>>a[i];
	v[60].push_back(0);
	v[60].push_back(((LL)1<<60)-1);
	for(k=59;k>=0;k=k-1){
		s=v[k+1].size();
		j=0;
		v[k].push_back(0);
		for(i=1;i<s;i=i+1){
			while(j<n&&!((a[j]>>k)&1)){
				j++;
			}
			if((v[k+1][i]>>k)&1){
				if(j<n){
					v[k].push_back(a[j]);
					a[j]=0;
				}
			}
			v[k].push_back(v[k+1][i]);
		}
		for(j=0;j<n;j=j+1)
			if((a[j]>>k)&1){
				cout<<"No\n";
				return 0;
			}
	}
	cout<<"Yes\n";
	for(j=1;j<=n;j=j+1)
		cout<<v[0][j]<<' ';
	return 0;
}