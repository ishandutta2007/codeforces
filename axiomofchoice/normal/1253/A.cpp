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
int t,n,a[N],b[N];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int cnt=0,m=1e17,M=-1;
		repeat(i,0,n)cin>>a[i];
		repeat(i,0,n)cin>>b[i];
		repeat(i,0,n){
			if(a[i]!=b[i]){
				m=min(m,i);
				M=max(M,i);
				cnt++;
			}
		}
		if(cnt==0){cout<<"Yes"<<endl;continue;}
		if(cnt!=M-m+1){cout<<"No"<<endl;continue;}
		if(cnt==M-m+1){
			int del=b[m]-a[m],f=1;
			if(del<0){cout<<"No"<<endl;continue;}
			repeat(i,m,M+1){
				if(b[i]-a[i]!=del)
					f=false;
			}
			if(f)cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
	return 0;
}