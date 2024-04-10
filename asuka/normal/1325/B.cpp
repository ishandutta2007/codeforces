#include<bits/stdc++.h>
#define ll long long
#define N 100015
using namespace std;
int t,n,a[N]; 
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 1;i <= n;++i)
			cin >> a[i];
		sort(a+1,a+n+1);
		cout << unique(a+1,a+n+1)-a-1 << endl;
	}
	return 0;
}