#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll;
//#define int ll
int T,a,b,ans;
signed main(){
	cin>>T;
	while(T--){
		ans=0;
		cin>>a>>b;
		if(a>b)swap(a,b);
		int t=min({a,b/2,b-a});
		a-=t; b-=2*t; ans+=t;
		t=min({a/3,b/3});
		a-=t*3; b-=t*3; ans+=2*t;
		if(a && b && a+b>=3)ans++;
		cout<<ans<<endl;
	}
	return 0;
}