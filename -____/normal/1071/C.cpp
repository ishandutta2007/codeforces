//CF1071C
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
int n,a[N];
vector<int> v[3];
void pr(int l,int r){
	int x=l+r>>1;
	a[l]^=1,a[x]^=1,a[r]^=1;
	v[0].push_back(l);
	v[1].push_back(x);
	v[2].push_back(r);
}
void solve(int l,int r){
	if(l>r)
		return;
	//cout<<l<<r<<endl;
	if(!a[l]){
		solve(l+1,r);
		return;
	}
	if(!a[r]){
		solve(l,r-1);
		return;
	}
	if(l==r){
		if(n<7||(n==7&&l%3!=1)){
			cout<<"NO";
			exit(0);
		}
		if(n==8&&l==6){
			pr(6,8);
			solve(7,7);
			solve(8,8);
			return;
		}
		if(l<7){
			pr(l,l+2);
			pr(l+1,l+3);
			solve(l+3,l+3);
		}
		else{
			pr(l-6,l);
			pr(l-4,l-2);
			pr(l-6,l-2);
		}
		return;
	}
	if(r-l==1){
		if(n<7){
			cout<<"NO";
			exit(0);
		}
	}
	if(r-l+1<=8){
		if(r==n){
			pr(r-2,r);
			solve(min(l,r-2),r-1);
		}
		else{
			pr(l,l+2);
			solve(l+1,max(r,l+2));
		}
		return;
	}
	if(a[l+1]&&a[l+2]){
		pr(l,l+2);
		solve(l+3,r);
		return;
	}
	if(a[r-2]&&a[r-1]){
		pr(r-2,r);
		solve(l,r-3);
		return;
	}
	if(a[l+2]){
		pr(l,l+4);
		solve(l+3,r);
		return;
	}
	if(a[r-2]){
		pr(r-4,r);
		solve(l,r-3);
		return;
	}
	if(!a[l+1]){
		pr(l,l+6);
		solve(l+3,r);
		return;
	}
	if(!a[r-1]){
		pr(r-6,r);
		solve(l,r-3);
		return;
	}
	if((r-l)&1){
		pr(l,r-1);
		pr(l+1,r);
		solve(l+3,r-3);
	}
	else{
		pr(l,r);
		pr(l+1,r-1);
		solve(l+3,r-3);
	}
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)	
		scanf("%d",a+i);
	solve(1,n);
	cout<<"YES\n"<<v[0].size()<<endl;
	for(i=v[0].size();i--;)
		cout<<v[0][i]<<' '<<v[1][i]<<' '<<v[2][i]<<endl;
	return 0;
}