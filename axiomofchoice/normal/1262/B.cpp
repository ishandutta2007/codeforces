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
#define inf mod
int T,a[N],ans[N],n,f[N]; 
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		repeat(i,0,n+1)f[i]=ans[i]=0;
		repeat(i,0,n){
			cin>>a[i];
			if(i==0 || a[i]!=a[i-1]){
				ans[i]=a[i];
				f[a[i]]=1;
			}
		}
		int p=1;
		repeat(i,0,n){
			if(ans[i]==0){
				while(f[p])p++;
				f[p]=1;
				ans[i]=p;
			}
		}
		bool flag=true;
		repeat(i,0,n+1)f[i]=0;
		repeat(i,0,n){
			if(ans[i]>a[i])flag=false;
			if(f[ans[i]])flag=false;
			f[ans[i]]=1;
		}
		if(!flag)cout<<-1;
		else repeat(i,0,n)cout<<ans[i]<<' ';
		cout<<endl;
	}
	return 0;
}