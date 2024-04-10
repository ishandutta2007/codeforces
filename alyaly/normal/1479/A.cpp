#include<bits/stdc++.h>
#define int long long
#define N 1000000
using namespace std;
int T,n,a[N+1];
int chk(int x){
	cout.flush();
	cout<<"? "<<x<<endl;
	int nans;cin>>nans;return nans;
}
signed main(){
	cin>>n;
	int l=1,r=n;
	while(l!=r){
		int mid=(l+r)/2;
		int np=chk(mid),nq=chk(mid+1);
		if(np>nq)l=mid+1;
		else r=mid;
	}
	cout<<"! "<<l<<endl;
	return 0;
}