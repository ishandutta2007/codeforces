#include <bits/stdc++.h>

using namespace std;

const int MAXN=1000 * 1000 + 10;

int n, tmp, out;
int ans[MAXN];
string s;

stack<int> st;
map<int, int> mp;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	getline(cin, s);
	n=s.size();
	for (int i=0; i<n; i++){
		if (s[i]==')'){
			if (!st.empty()){
				ans[i]=i-st.top()+1 + ans[st.top()-1];
				st.pop();
				mp[ans[i]]++;
				out=max(out, ans[i]);
			}
		}
		else{
			st.push(i);
		}
		//cout<<ans<<' '<<x<<endl;
	}
	mp[0]=1;
	cout<<out<<' '<<mp[out]<<endl;
	
	return 0;
}