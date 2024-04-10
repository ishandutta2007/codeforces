# include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	string a;
	cin >> n >> a;
	stack <char> st;
	for (int i=0; i<n; i++){
		if (a[i] == ')' and st.size() > 0 and st.top() == '(') st.pop();
		else st.push(a[i]);
	}
	if (st.size() == 0) cout <<  "Yes";
	else if (st.size() == 2){
		if (st.top() != '(') cout << "No";
		else {
			st.pop();
			if (st.top() == '(') cout << "No";
			else cout << "Yes";
		} 
	}
	else{
		cout << "No";
	}
}