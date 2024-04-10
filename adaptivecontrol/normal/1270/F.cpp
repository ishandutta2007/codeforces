#include<bits/stdc++.h>
using namespace std;
const int T=300;
int n,cnt[60000003],a[200003];string s;
vector<int>v;
long long ans;
int main(){
	cin>>s;n=s.size();
	for(int i=1;i<=n;i++)
		a[i]=a[i-1]+s[i-1]-'0';
	for(int i=1;i<=T;i++){
		v.clear();
		for(int j=0;j<=n;j++)
			v.push_back(a[j]*i-j+n),
			ans+=cnt[v.back()]++;
		for(int j=0;j<v.size();j++)
			cnt[v[j]]=0;
	}
	for(int k=n/T;k;k--){
		int l=0;
		while(l<n&&a[l+1]<k)l++;
		if(l==n)continue;
		int r=l+1;
		while(r<n&&a[r+1]<=k)r++;
		for(int i=0;i<n;i++){
			if(a[r]-a[i]<k){
				if(r==n)break;
				l=r;
				while(r<n&&a[r+1]-a[i]<=k)r++;
			}
			if((r-i)/k>T)
				ans+=(r-i)/k-max((l-i)/k,T); 
		}
	}
	cout<<ans;
}