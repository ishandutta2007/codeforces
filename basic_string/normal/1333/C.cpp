#include<bits/stdc++.h>
using namespace std;
unordered_map<long long,int>mp;
const int N=2e5+3;
long long a[N];
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int main(){
	int n,i,j,l=1;
	long long s=0,t=0;
	cin>>n,mp.reserve(2*n+rd()%99999);
	for(i=1;i<=n;++i){
		cin>>j,++mp[a[i]=t];
		while(mp[j+t])--mp[a[l]],++l;
		s+=i-l+1,t+=j;
	}
	cout<<s;
	return 0;
}