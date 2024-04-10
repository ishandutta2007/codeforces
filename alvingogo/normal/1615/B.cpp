#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

int calc(int r,int v){
	r++;
	int x=r%(2*v);
	int h=(r-x)/2;
	if(x>v){
		h+=x-v;
	}
	return h;
}
int main(){
	AquA;
	int t;
	cin >> t;
	while(t--){
		int l,r;
		cin >> l >> r;
		int ans=9999999;
		for(int i=0;i<20;i++){
			int x=calc(r,(1<<i))-calc(l-1,(1<<i));
			if(r-l+1-x<ans){
				ans=r-l+1-x;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}