#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		for(int i= 1; i<=N; i++){
			int n;
			cin >> n;
			v.push_back(n);
		}
		sort(v.begin(), v.end());
		set<int> st;
		for(int i = 0; i<N; i++){
			for(int j = i+1;j <N;j ++){
				st.insert(abs(v[i]-v[j]));
			}
		}
		set<int> temp;
		for(int n : st){
			for(int k = 1; k<N; k++){
				if(n%k == 0){
					temp.insert(n/k);
				}
			}
		}
		for(int i = 1; 1; i++){
			if(!temp.count(i)){
				cout << "YES\n";
				for(int j = 1; j<=1+(N-1)*i; j+=i){
					cout << j << " ";
				}
				cout << "\n";
				break;
			}			
		}
		v.clear();
	}
}