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
int n,x0,y0,x,y,r=0,l=0,u=0,d=0,m;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>x0>>y0;
	repeat(i,0,n){
		cin>>x>>y;
		if(x>x0)r++;
		if(x<x0)l++;
		if(y>y0)u++;
		if(y<y0)d++;
	}
	m=max(max(max(r,l),u),d);
	if(r==m){
		cout<<m<<endl;
		cout<<x0+1<<' '<<y0<<endl;
		exit(0);
	}
	if(l==m){
		cout<<m<<endl;
		cout<<x0-1<<' '<<y0<<endl;
		exit(0);
	}
	if(u==m){
		cout<<m<<endl;
		cout<<x0<<' '<<y0+1<<endl;
		exit(0);
	}
	if(d==m){
		cout<<m<<endl;
		cout<<x0<<' '<<y0-1<<endl;
		exit(0);
	}
    return 0;
}