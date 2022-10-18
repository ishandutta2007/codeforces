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
		int n;
		cin >> n;
		vector<int> v(n),bg,sm;
		string s;
		for(int i=0;i<n;i++){
			cin >> v[i];
		}
		cin >> s;
		int a=1;
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				a++;
				sm.push_back(v[i]);
			}
			else{
				bg.push_back(v[i]);
			}
		}
		sort(bg.begin(),bg.end());
		sort(sm.begin(),sm.end());
		for(int i=0;i<n;i++){
			int b;
			if(s[i]=='0'){
				cout << lower_bound(sm.begin(),sm.end(),v[i])-sm.begin()+1 << " ";	
			}
			else{
				cout << lower_bound(bg.begin(),bg.end(),v[i])-bg.begin()+a << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}