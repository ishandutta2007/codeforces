#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

int main(){
	AquA;
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		string s;
		cin >> s;
		int ans=0;
		for(int i=0;i<n;i++){
			ans+=(s[i]-'0');
		}
		if(1ll*ans*m%n!=0){
			cout << -1 << "\n";
			continue;
		}
		int u=1ll*ans*m/n;
		int l=0;
		int c=0,flag=-1;
		for(int i=0;i<m;i++){
			c+=(s[i]-'0');
		}
		for(;l+m-1<n;l++){
			if(c==u){
				flag=l;
				break;
			}
			if(l+m-1==n-1){
				break;
			}
			c-=s[l]-'0';
			c+=s[l+m]-'0';
		}
		if(flag>=0){
			cout << 1 << "\n";
			cout << flag+1 << " " << flag+m << "\n";
		}
		else{
			c=0,flag=-1;
			for(int i=0;i<m;i++){
				c+=(s[i]-'0');
			}
			int r=m-1;
			while(r>0){
				c-=s[r]-'0';
				c+=s[(n-(m-r))]-'0';
				r--;
				if(c==u){
					cout << 2 << "\n";
					cout << 1 << " " << r+1 << "\n";
					cout << n-(m-r)+2 << " " << n << "\n"; 
					break;
				}
			}
		}
	}
	return 0;
}