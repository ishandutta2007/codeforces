#include <bits/stdc++.h>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		int n,x;
		cin >> n >> x;
		vector<int> a(n),b(n);
		for(int i=0;i<n;i++){
			cin >> a[i];
			b[i]=a[i];
		}
		sort(a.begin(),a.end());
		int f=0;
		for(int i=n-x;i<x;i++){
			if(a[i]!=b[i]){
				f=1;
				break;
			}
		}
		if(f==1){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
	return 0;
}