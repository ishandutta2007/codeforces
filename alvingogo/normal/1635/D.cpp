#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

const int mod=1e9+7;
int main(){
	AquA;
	int n,p;
	cin >> n >> p;
	set<int> s;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		s.insert(a);
	}
	vector<int> v;
	for(auto h:s){
		int z=h;
		int flag=0;
		while(z>0 && (z%4==0 || z%2==1)){
			if(z%4==0){
				z/=4;
			}
			else{
				z/=2;
			}
			if(s.find(z)!=s.end()){
				flag=1;
				break;
			}
		}
		if(flag==0){
			v.push_back(h);
		}
	}
	vector<int> fab(p+5);
	fab[0]=fab[1]=1;
	for(int i=2;i<p+5;i++){
		fab[i]=(fab[i-1]+fab[i-2])%mod;
	}
	for(int i=1;i<p+5;i++){
		fab[i]+=fab[i-1];
		fab[i]%=mod;
	}
	int ans=0;
	for(auto h:v){
		int l=__lg(h);
		if(p-l-1>=0){
			ans+=fab[p-l-1];
			ans%=mod;
		}
	}
	cout << ans << "\n";
	return 0;
}