#include <bits/stdc++.h>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

const int mod=998244353;
int inv(int x){
	if(x==1){
		return 1;
	}
	return (1ll*(mod-mod/x)*inv(mod%x))%mod;
}
int main(){
	fastio;
	int t;
	cin >> t;
	vector<int> fra(200005);
	fra[0]=1;
	for(int i=1;i<200003;i++){
		fra[i]=1ll*fra[i-1]*i%mod;
	}
	//cout << inv(2) << endl;
	while(t--){
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin >> v[i];
		}
		int a=0,b=0,c=0;
		for(int i=0;i<n;i++){
			if(v[i]>a){
				if(v[i]>a+1){
					c=0;
					b=1;
					a=v[i];
				}
				else{
					c=b;
					b=1;
					a=v[i];
				}
			}
			else if(v[i]==a){
				b++;
			}
			else if(v[i]==a-1){
				c++;
			}
		}
		//cout << a << b << c << endl;
		int u=fra[n];
		if(b>1){
			cout << u << "\n";
			continue;
		}
		if(c>0){
			cout << (1ll*u*inv(b+c)%mod)*c%mod << "\n";
		}
		else{
			cout << 0 << "\n";
		}
	}
	return 0;
}