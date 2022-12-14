#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //typedef __int128 lll;
typedef pair<int,int> pii;
typedef double lf;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=1010;
const int inf=1e9;
const int mod=1000000007;
#define int ll
int a,b,c,d,c1,c2,ans=0;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>a>>b>>c>>d>>c1>>c2;
	if(c1>c2){
		int s=min(a,d);
		ans+=c1*s;
		d-=s,a-=s;
	}
	{
		int s=min(b,min(c,d));
		ans+=c2*s;
		b-=s,c-=s,d-=s;
	}
	{
		int s=min(a,d);
		ans+=c1*s;
		d-=s,a-=s;
	}
	cout<<ans<<endl;
    return 0;
}