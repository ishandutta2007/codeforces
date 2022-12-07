#include<bits/stdc++.h>
using namespace std;
int T,n,a[200003];
vector<int>v;
bool check(int x){
	v.clear();
	for(int i=0;i<n;i++)
		if(a[i]!=x)
			v.push_back(a[i]);
	for(int i=0;i<v.size();i++)
		if(v[i]!=v[v.size()-1-i])
			return 0;
	return 1;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		bool ok=1;
		for(int i=0;i<n;i++)
			if(a[i]!=a[n-i-1]){
				if(check(a[i])||check(a[n-i-1]))
					cout<<"YES\n";
				else
					cout<<"NO\n";
				ok=0;
				break;
			}
		if(ok)
			cout<<"YES\n";
	}
}