#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e2+5;
int n,m,a[N],b[N],p[N],ans; 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)cin>>b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	for(int i=1;i<=n;i++){
		int pos=0;
		for(int j=1;j<=m;j++)if(!p[j]&&(!pos||b[j]<b[pos])&&abs(b[j]-a[i])<2)pos=j;
		if(pos)p[pos]=1,ans++;
	}
	cout<<ans<<endl;
    return 0;
}