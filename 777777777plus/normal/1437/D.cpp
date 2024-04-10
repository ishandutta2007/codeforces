#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
 
int T;
int n,a[N],f[N];
 
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
		}
		int ans=1;
		int tot=1,nextot=0;
		for(int i=2;i<=n;++i){
			if(a[i]>a[i-1]){
				nextot++;
			}
			else{
				tot--;
				if(!tot){
					tot=nextot;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
}