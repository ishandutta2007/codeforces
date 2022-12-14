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
#define inf mod
pii a[N],b[N];
int n,m,k,pos,x;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	repeat(i,0,n)cin>>x,a[i]={-x,i};
	sort(a,a+n);
	cin>>m;
	repeat(i,0,m){
		cin>>k>>pos;
		repeat(j,0,k)b[j]=a[j];
		sort(b,b+k,[](pii a,pii b){return a.second<b.second;});
		cout<<-b[pos-1].first<<endl;
	}
	return 0;
}