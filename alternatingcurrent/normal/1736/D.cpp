#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;

int n;
string s;
bool inb[200200];

int main(){
	ios::sync_with_stdio(false);
	
	int T;
	cin >> T;
	while(T--){
		cin >> n >> s;
		n *= 2;
		rep(i, n)
			inb[i] = 0;
		
		set<int> st;
		rep(i, n)
			if(s[i] - '0')
				st.insert(i);
		
		bool ok = 1;
		for(int i = 0; i < n && ok; i += 2){
			if(s[i] != s[i+1]){
				int id = i + (s[i+1] == '0');
				auto nxt1 = st.lower_bound(i+2);
				if(nxt1 == st.end()){
					ok = 0;
					break;
				}
				inb[id] ^= 1, inb[*nxt1] ^= 1;
				swap(s[id], s[*nxt1]);
				st.erase(nxt1);
			}
		}
		
		if(!ok)
			cout << "-1\n";
		else {
			int sz = 0;
			rep(i, n)
				sz += inb[i];
			cout << sz << " ";
			
			rep(i, n)
				if(inb[i])
					cout << i+1 << " ";
			cout << "\n";
			
			for(int i = 0; i < n; i += 2)
				cout << i+1 << " ";
			cout << "\n";
		}
	}
	
	return 0;
}