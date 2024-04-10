#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

struct no{
	int a,b;
	int id;
};
bool cmp(no a,no b){
	return a.a<b.a;
}
int main(){
	AquA;	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<no> v(n);
		for(int i=0;i<n;i++){
			cin >> v[i].a;
			v[i].id=i;
		}
		for(int i=0;i<n;i++){
			cin >> v[i].b;
		}
		sort(v.begin(),v.end(),cmp);
		vector<bool> ans(n);
		int ma=n-1,mx=v[n-1].b,uu=v[n-1].b;
		for(int i=n-2;i>=0;i--){
			if(v[i].b>mx){
				ma=i;
				mx=uu;
			}
			uu=min(uu,v[i].b);
		}
		for(int i=ma;i<n;i++){
			ans[v[i].id]=1;
		}
		for(int i=0;i<n;i++){
			cout << ans[i]?"1":"0";
		}
		cout << "\n";
	}
	return 0;
}