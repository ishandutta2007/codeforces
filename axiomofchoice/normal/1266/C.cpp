#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //typedef __int128 lll;
typedef pair<int,int> pii;
typedef double lf;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=400010;
const int inf=1e9;
const int mod=998244353;
#define int ll
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int x,y; cin>>x>>y;
	if(x==1 && y==1){cout<<0<<endl; exit(0);}
	repeat(i,1,x+1)
	repeat(j,1,y+1){
		int a=i,b=x+j;
		if(y==1)a=y+i,b=j;
		cout<<a/__gcd(a,b)*b<<" \n"[j==y];
	}
	return 0;
}