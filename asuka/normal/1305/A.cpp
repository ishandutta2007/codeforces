#include<bits/stdc++.h>
#define ll long long
#define N 105 
using namespace std;
int t,n,a[N],b[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 1;i <= n;++i) cin >> a[i];
		for(int i = 1;i <= n;++i) cin >> b[i];
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		for(int i = 1;i <= n;++i) cout << a[i] << ' ';
		cout << endl;
		for(int i = 1;i <= n;++i) cout << b[i] << ' ';
		cout << endl;
	}
	return 0;
}