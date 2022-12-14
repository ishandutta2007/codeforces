#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define N 1000010
#define mod 2147483647
#define int ll
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin>>n;
	repeat(i,2,sqrt(n+1.5)+2)
	if(n%i==0){
		while(n%i==0)n/=i;
		if(n==1){
			cout<<i<<endl;
			return 0;
		}
		else{
			cout<<1<<endl;
			return 0;
		}
	}
	cout<<n<<endl;
	return 0;
}