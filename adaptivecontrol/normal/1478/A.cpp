#include<bits/stdc++.h>
using namespace std;
int T,n,a[103];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		int ans=0;
		for(int i=0;i<n;i++){
			int cnt=0;
			for(int j=0;j<n;j++) 
				if(a[i]==a[j])
					cnt++;
			ans=max(ans,cnt);
		}cout<<ans<<endl;
	}
}