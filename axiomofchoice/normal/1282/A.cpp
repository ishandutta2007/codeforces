#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //typedef __int128 lll;
typedef pair<int,int> pii;
typedef long long lf;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=100010;
const int inf=1e9;
const int mod=1000000007;
//#define int ll
ll a,b,c,r,t;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>r; if(a>b)swap(a,b);
		if(c-r>=b || c+r<=a)
			cout<<b-a<<endl;
		else{
			ll n=0;
			if(c-r<a && a<c+r)
				n+=c+r-a;
			if(c-r<b && b<c+r)
				n+=b-c+r;
			if(a<=c-r && c+r<=b)
				n+=2*r;
			cout<<max(0ll,b-a-n)<<endl;
		}
	}
	return 0;
}