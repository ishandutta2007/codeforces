#include <iostream>
#include <stack>
using namespace std;

const int N = 100 * 1000 + 5;

int a[N];
int kill[N];
int dtht[N];
stack <int> st;

int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		dtht[i] = N;
		cin >> a[i];
		while (st.size() && (a[i] > a[st.top()] || dtht[st.top()] < kill[st.top()]))
			st.pop();
		if (st.size()) {
			dtht[i] = kill[st.top()];
			kill[st.top()]++;
		}
	//	cout << dtht[i] << " ";	
		st.push(i);
		
	}
	//cout << endl;
	for (int i = 0; i < n; i++) {
		ans = max(ans, kill[i]);
	//	cout << kill[i] << " ";
	}
	//cout << endl;
	cout << ans << endl;
	return 0;
}