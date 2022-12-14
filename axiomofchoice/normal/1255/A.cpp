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
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		if(a>b)swap(a,b);
		int ans=(b-a)/5;
		b-=ans*5;
		if(b-a>=3)ans+=2;else if(b-a!=0)ans+=1;
		cout<<ans<<endl;
	}
	return 0;
}