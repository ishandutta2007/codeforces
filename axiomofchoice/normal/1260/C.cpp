#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define N 100010
//#define mod 1000000007
#define int ll
#define inf mod
#define qwq {cout<<"qwq"<<endl;}
int T,a,b,k,g;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		cin>>a>>b>>k;
		if(a>b)swap(a,b);
		g=__gcd(a,b);
		//*.....*
		if((b-g-1)/a+1<k)cout<<"OBEY"<<endl;
		else cout<<"REBEL"<<endl;
	}
	return 0;
}