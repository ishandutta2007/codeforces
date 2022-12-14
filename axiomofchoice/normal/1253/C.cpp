#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define N 200010
#define mod 1000000007
#define int ll
int t,n,m,a[N],s[N];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	repeat(i,1,n+1)
		cin>>a[i];
	sort(a+1,a+n+1);
	int sum=0;
	repeat(k,1,n+1){
		s[k%m]+=a[k];
		sum+=s[k%m];
		cout<<sum<<' ';
	}
	cout<<endl;
	return 0;
}