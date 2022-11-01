# include <bits/stdc++.h>

using namespace std;

const int xn = 2e5;
int gh[xn];

int main(){
	int n, m;
	cin >> n >> m;
	string a;
	cin >> a;
	int t = 0;
	for (int i=n-1; i>=0; i--){
		if (a[i] == ')') t++;
		else gh[i] = t;
	}
	t = 0;
	string b = "";
	for (int i=0; i<n; i++){
		if (a[i] == ')' and t > 0)
			b += a[i], t--;
		else if (a[i] == '(' and t+1 <= gh[i])
			b += a[i], t++;
	}
	//cout << b << endl;
	t = (b.size()-m)/2;
	//cout << "t : " << t << endl;
	deque <char> st;
	for (int i=0; i<b.size(); i++){
		if (b[i] == '(') st.push_back(b[i]);
		else if (t > 0) st.pop_back(), t -= 1;
		else st.push_back(b[i]);
	}
	for (int i=0; i<st.size(); i++) cout << st[i];
	return 0;
}