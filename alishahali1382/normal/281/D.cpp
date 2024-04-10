#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN=100 * 1000 + 10;

int n, ans;
int A[MAXN];

stack<int> st;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>A[i];
		while (!st.empty() && A[i]>st.top()){
			ans=max(ans, A[i]^st.top());
			st.pop();
		}
		if (!st.empty()) ans=max(ans, A[i]^st.top());
		st.push(A[i]);
	}
	cout<<ans<<endl;
	return 0;
}