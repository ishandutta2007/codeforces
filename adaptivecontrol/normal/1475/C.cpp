#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,a[200003],b[200003],cnt[2][200003];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		for(int i=0;i<k;i++)scanf("%d",a+i);
		for(int i=0;i<k;i++)scanf("%d",b+i);
		long long ans=0;
		for(int i=0;i<k;i++){
			ans=ans+i-cnt[0][a[i]]-cnt[1][b[i]];
			cnt[0][a[i]]++;cnt[1][b[i]]++;
		}
		cout<<ans<<endl;
		for(int i=0;i<k;i++){
			cnt[0][a[i]]--;cnt[1][b[i]]--;
		}
	}
}