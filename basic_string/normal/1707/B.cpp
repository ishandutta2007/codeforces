#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
basic_string<int>a,b;
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,i,j,k,T;
	for(cin>>T;T--;){
		cin>>n;a={};
		for(i=1;i<=n;++i){
			cin>>j;
			if(j)a+=j;
		}
		for(i=n;i>1;--i){
			b={};
			int l=a.size();
			if(l&&l<i){
				b+=a[0];
			}
			for(int j=1;j<l;++j){
				if(a[j]-a[j-1])b+=a[j]-a[j-1];
			}
			swap(a,b),sort(begin(a),end(a));
		}
		if(a.size())cout<<a[0]<<'\n';
		else cout<<0<<'\n';
	}
}