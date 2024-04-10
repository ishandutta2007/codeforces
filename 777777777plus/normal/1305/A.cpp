#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;


int T;
int n,a[N],b[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=n;++i)cin>>b[i];
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		for(int i=1;i<=n;++i)cout<<a[i]<<" ";
		cout<<endl;
		for(int i=1;i<=n;++i)cout<<b[i]<<" ";
		cout<<endl;
	}
}