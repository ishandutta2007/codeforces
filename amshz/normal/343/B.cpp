# include <bits/stdc++.h>

using namespace std;

int main(){
	string a;
	cin >> a;
	int t = 0;
	bool f = 1;
	stack <char> st;
	for (int i=0; i<a.size(); i++){
		if (st.size() == 0) st.push(a[i]);
		else if (st.top() == a[i]) st.pop();
		else st.push(a[i]);
	}
	if (st.size() != 0) cout << "No";
	else cout << "Yes";
}