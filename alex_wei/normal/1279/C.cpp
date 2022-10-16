#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,m,a[100005],b[100005],pos,ans,pd[100005];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		memset(pd,0,sizeof(pd));
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=m;i++)cin>>b[i];
		pos=0,ans=0;
		for(int i=1;i<=m;i++){
			ll tp=0;
			while(!pd[b[i]])tp=1,pd[a[++pos]]=1;
			if(tp)ans+=2*(pos-i)+1;
			else ans++;
		}
		cout<<ans<<endl;
	}
    return 0;
}