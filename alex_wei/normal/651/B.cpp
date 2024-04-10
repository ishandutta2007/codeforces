#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,a[N],p[N],pre,ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int pos=0;
		if(i>1){
			for(int j=1;j<=n;j++){
				if(!p[j]&&a[j]>pre&&(!pos||a[pos]>a[j]))pos=j;
			}
			if(pos)p[pos]=1,pre=a[pos],ans++;
		}
		if(!pos){
			for(int j=1;j<=n;j++){
				if(!p[j]&&(!pos||a[pos]>a[j]))pos=j;
			}
			pre=a[pos],p[pos]=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}