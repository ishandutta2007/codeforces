#include<bits/stdc++.h>
#define ll long long
#define N
using namespace std;
int t,n,a[105];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 1;i <= n;++i) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i = n;i > 0;--i) cout << a[i] << ' ';
		cout << endl;
	}
	return 0;
}