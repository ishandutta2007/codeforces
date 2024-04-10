#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define N 100010
#define mod 1000000007
#define int ll
pii a[1010];
int n,m;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n>>m;
		int sum=0;
		repeat(i,0,n)
			cin>>a[i].first,a[i].second=i,sum+=a[i].first;
		sort(a,a+n);
		if(n==2 || m<n){
			cout<<-1<<endl;
			continue;
		}
		sum*=2;
		sum+=(a[0].first+a[1].first)*(m-n);
		cout<<sum<<endl;
		repeat(i,0,m-n)
			cout<<a[0].second+1<<' '<<a[1].second+1<<endl;
		repeat(i,0,n)
			cout<<i+1<<' '<<(i+1)%n+1<<endl;
	}
	return 0;
}