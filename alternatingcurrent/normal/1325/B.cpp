#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		set<int> st;
		cin >> n;
		rep(i, n){
			int a;
			cin >> a;
			st.insert(a);
		}
		cout << st.size() << endl;
	}
	return 0;
}