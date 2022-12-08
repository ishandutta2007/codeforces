#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
 
int n,m,a[N],p[N];
ll suf[N];
 
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;++i)cin>>a[i];
	for(int i=m;i>=1;--i)suf[i]=suf[i+1]+a[i];
	int pos=0;
	for(int i=1;i<=m;++i){
		if(suf[i]<n-pos){
			cout<<-1<<endl;
			return 0;
		}
		if(suf[i]>=n-p[i-1])p[i]=p[i-1]+1;
		else p[i]=n-suf[i]+1;
		pos=max(pos,p[i]+a[i]-1);
		if(p[i]>n-a[i]+1){
			cout<<-1<<endl;
			return 0;
		}
	}
	for(int i=1;i<=m;++i)cout<<p[i]<<" ";
	cout<<endl;
}