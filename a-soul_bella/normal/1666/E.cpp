#include <bits/stdc++.h>
#define int long long
#define ll long long
#define db double
#define fi first
#define se second
#define pii pair<int,int>
#define vi vector<int>

using namespace std;

const int maxn=1e6; 

int n,L;  
int a[maxn+5],lp[maxn+5],rp[maxn+5]; 
 
int check1(int x) {
	int lst=0;
	for (int i=1;i<=n;i++) {
		lst=max(lst+x,a[i]); 
		if (lst>a[i+1]) {
			return 0; 
		}
	}
	return 1; 
}
int check2(int Lx,int Rx) {
	lp[0]=rp[0]=0;
	for (int i=1;i<=n;i++) {
		lp[i]=lp[i-1]+Lx;
		rp[i]=rp[i-1]+Rx;
		if (rp[i]<a[i] || lp[i]>a[i+1]) return 0; 
		rp[i]=min(rp[i],a[i+1]);
		lp[i]=max(lp[i],a[i]);
	}
	return rp[n]==L;
}
signed main() {
//	freopen("in.txt","r",stdin);
//	freopen("std.out","w",stdout); 
	scanf("%lld %lld",&L,&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]); 
	int l=1,r=1e9,ansmin=1e9; 
	a[n+1]=L; 
	while (l<=r) {
		int mid=(l+r)>>1;
		if (check1(mid)) {
			ansmin=mid;
			l=mid+1; 
		}
		else {
			r=mid-1; 
		}
	}
	l=ansmin,r=1e9; 
	int ansmx=ansmin;
	while (l<=r) {
		int mid=(l+r)>>1;
		if (check2(ansmin,mid)) {
			ansmx=mid;r=mid-1; 
		}
		else l=mid+1; 
	}
	check2(ansmin,ansmx);
	int MN=1e9,MX=0; 
	for (int i=n-1;i>=0;i--) {
		rp[i]=min(rp[i],rp[i+1]-ansmin); 
	}
	for (int i=0;i<n;i++) printf("%lld %lld\n",rp[i],rp[i+1]); 

	return 0;
}