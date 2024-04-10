#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

const int MAXN=5010;

int n, w, h, a, b, m;
int dp[MAXN];
int P[MAXN];
piii A[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>w>>h;
	for (int i=0; i<n; i++){
		cin>>a>>b;
		if (a<=w || b<=h) continue ;
		A[m++]={{a, b}, i+1};
	}
	n=m;  // !!!
	sort(A, A+n);
	dp[0]=1;
	P[0]=-1;
	int mx=0;
	for (int i=1; i<n; i++){
		//cout<<A[i].first.first<<' '<<A[i].first.second<<endl;
		P[i]=-1;
		dp[i]=1;
		for (int j=0; j<i; j++){
			if (A[i].first.first==A[j].first.first || A[j].first.second>=A[i].first.second) continue ;
			//cout<<A[j].first.first<<endl;
			if (dp[j]+1>=dp[i]){
				dp[i]=dp[j]+1;
				P[i]=j;
			}
		}
		if (dp[i]>dp[mx]) mx=i;
	}
	if (!n){
		cout<<0<<endl;
		return 0;
	}
	cout<<dp[mx]<<endl;
	stack<int> st;
	for (int i=mx; i!=-1; i=P[i]){
		st.push(A[i].second);
	}
	while (!st.empty()) {
		cout<<st.top()<<' ';
		st.pop();
	}
	cout<<endl;
	return 0;
}