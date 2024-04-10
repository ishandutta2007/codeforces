#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,l;
		cin>>n>>l;
		for(int i=1;i<=n;++i)cin>>a[i];
		int ans=0;
		for(int i=0;i<l;++i){
			int c1=0,c2=0;
			for(int j=1;j<=n;++j){
				int wz=(a[j]>>i)&1;
				if(wz==0)++c1;
				else ++c2;
			}
			if(c1<c2)ans|=1<<i;
		}
		cout<<ans<<endl;
	}
	return 0;
}