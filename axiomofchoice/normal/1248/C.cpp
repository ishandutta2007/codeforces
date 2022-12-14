#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
ll mod=1000000007;
ll n,m;
ll f[100010];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	f[0]=1,f[1]=1;
	repeat(i,2,100010)f[i]=(f[i-1]+f[i-2])%mod;
	cin>>n>>m;
	cout<<2*(f[n]+f[m]-1)%mod<<endl;
	return 0;
}