#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=110; typedef long long ll;
#define int ll
int T,n,m;
string s;
int a[N];
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		repeat(i,0,n){
			cin>>s;
			a[i]=bitset<64>(s).to_ullong();
		}
		sort(a,a+n);
		int l=0,r=1ll<<m,f=((1ll<<m)-n-1)/2;
		while(l<=r){
			int mid=(l+r)/2;
			int cnt=mid-(upper_bound(a,a+n,mid)-a);
			if(cnt<f)l=mid+1; else r=mid-1;
		}
		cout<<bitset<64>(l).to_string().substr(64-m,-1)<<endl;
	}
	return 0;
}