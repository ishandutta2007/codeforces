#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,buc[1000005],a[3005],b[3005],p[3005],ans;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	for(int i=1;i<=n;i++){
		int d=0;
		for(int j=1;j<=m;j++){
			if(!p[j]&&b[j]>=a[i]){
				d=1;
				p[j]=1;
				break;
			}
		}
		ans+=!d;
	}
	cout<<ans<<endl;
    return 0;
}