#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define N 100010
#define mod 1000000007
//#define int ll
#define inf mod
int T,n,mx,x,my,y;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		mx=-inf,my=inf;
		repeat(i,0,n){
			cin>>x>>y;
			my=min(my,y);
			mx=max(mx,x);
		}
		if(my>=mx)cout<<0<<endl;
		else cout<<abs(my-mx)<<endl;
	}
	return 0;
}