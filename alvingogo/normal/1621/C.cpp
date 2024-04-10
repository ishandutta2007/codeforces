#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

int query(int x){
	cout << "? " << x << endl;
	int y;
	cin >> y;
	return y;
}
int main(){
	//AquA;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		
		vector<int> v(n+1,0);
		for(int i=1;i<=n;i++){
			if(!v[i]){
				int u=query(i),z=u;
				do{
					int h=query(i);
					v[u]=h;
					u=h;
				}
				while(u!=z || !v[i]);
			}
		}
		cout << "! ";
		for(int i=1;i<=n;i++){
			cout << v[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}