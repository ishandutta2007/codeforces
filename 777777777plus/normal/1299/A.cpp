#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n,a[N],cnt[N];

int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		for(int j=30;~j;--j)if(a[i]&1<<j)cnt[j]++;
	}
	int res=0;
	for(int i=30;~i;--i)if(cnt[i]==1)res|=1<<i;
	int ans=0;
	for(int i=1;i<=n;++i)if((res&a[i])>=(res&a[ans]))ans=i;
	cout<<a[ans]<<" ";
	for(int i=1;i<=n;++i)if(i!=ans)cout<<a[i]<<" ";
	cout<<endl;
}