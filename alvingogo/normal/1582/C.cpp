#include <bits/stdc++.h>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
using namespace std;

int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		s="$"+s+"$";
		n+=2;
		int ans=64216914;
		for(char c='a';c<='z';c++){
			vector<int> v;
			string t;
			int z=-1;
			for(int i=0;i<n;i++){
				if(s[i]==c){
					v[z]++;
				}
				else{
					t+=s[i];
					v.push_back(0);
					z++;
				}
			}
			string l=t;
			int g=t.length();
			reverse(t.begin(),t.end());
			if(t==l){
				v.pop_back();
				vector<int> f=v;
				reverse(v.begin(),v.end());
				int k=g;
				for(int i=0;i<g-1;i++){
					k+=min(v[i],f[i]);
				}
				ans=min(ans,n-k);
			}
		}
		if(ans==64216914){
			cout << -1 << "\n";
		}
		else{
			cout << ans << "\n";
		}
	}
	return 0;
}