/*
 * test.cpp
 *
 *
 *      Author: Fireworks
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
#include<cmath>
#include<bitset>
#include<set>
#include<iomanip>
#include<fstream>
#include<bitset>
#include<cstring>
#include<cstdlib>
#include<complex>
#include<list>
#include<sstream>
#include<cassert>   // assert

using namespace std;

//#define double long double

typedef pair<int,int> ii;
typedef pair<int,long long> il;
typedef pair<long long,long long> ll;
typedef pair<ll,int> lli;
typedef pair<long long,int> li;
typedef pair<double,double> dd;
typedef pair<ii,int> iii;
typedef pair<double,int> di;
long long mod = 1000000007LL;
long long base = 10000007;
long long large = 1000000000000000000LL;


vector<int> val;
int up,uv;
void update(int o,int l,int r){
	if(l==r){
		val[o] = uv;
	}else{
		int m = (l+r)/2;
		if(up<=m) update(o*2,l,m);
		if(up>m) update(o*2+1,m+1,r);
		val[o] = val[o*2]|val[o*2+1];
	}
}

int ql,qr,re;
void query(int o,int l,int r){
	if(ql>qr) return ;
	if(ql<=l&&qr>=r){
		re |= val[o];
	}else{
		int m = (l+r)/2;
		if(ql<=m) query(o*2,l,m);
		if(qr>m) query(o*2+1,m+1,r);
	}
}
int main(){

	int n,k;
	cin>>n>>k;
	vector<int> a(n,0);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a.begin(),a.end());

	int low = 0;
	int high = 1000000000;
	int ans;
	while(low<=high){
		int mid = (low+high)/2;
		val.assign(4*n+20,0);
		up = 0;
		uv = 1;
		update(1,0,n);
		int lp = 0;
		for(int i=0;i<n;i++){
			qr = i-k+1;
			while(a[i]-a[lp]>mid) lp++;
			ql = lp-1+1;
			re = 0;
			query(1,0,n);
			up = i+1;
			uv = re;
			update(1,0,n);
		}

		ql=qr=n;
		re = 0;
		query(1,0,n);
		if(re==1){
			ans = mid;
			high = mid-1;
		}else{
			low = mid+1;
		}
	}
	cout<<ans<<endl;

	return 0;

}