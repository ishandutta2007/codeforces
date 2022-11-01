#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
// head

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int n = 27;
	int q1, q2;
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
			if(s[i] == s[j])
				q1 = i, q2 = j;
	if(q2-q1 == 1)
		return cout<<"Impossible",0;
	vector<vector<char>> ans(2,vector<char>(13,'0'));
	int tab = (q2 - q1 - 1) / 2;
	ans[0][13-tab-1] = s[q1];
	for(int i = 1; i <= tab; i++)
		ans[0][13-tab-1+i] = s[q1 + i];
	for(int i = 1; q1+tab+i < q2; i++)
		ans[1][13-i] = s[q1+tab+i];


if(q1 == 0) {
    queue<char> q;
					for(int k = q2+1; k < n; k++)
						q.push(s[k]);
					for(int k = 13-1; k >= 0; k--)
						if(ans[1][k] == '0')
							ans[1][k] = q.front(), q.pop();
					for(int k = 0; k < 13; k++)
						if(ans[0][k] == '0')
							ans[0][k] = q.front(), q.pop();
		for(int p = 0; p < 2; p++,cout<<"\n")
					for(int q = 0; q < 13; q++)
						cout << ans[p][q];
				return 0;					
							
}



	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 13; j++)
			if(ans[i][j] == '0' && (i ? 13-tab-1 + j +1 : 13-tab-1 -j) == q1) {
				if(i == 0) {
					for(int k = 0; ans[0][k+j] == '0'; k++)
						ans[0][k+j] = s[k];
					queue<char> q;
					for(int k = q2+1; k < n; k++)
						q.push(s[k]);
					for(int k = 13-1; k >= 0; k--)
						if(ans[1][k] == '0')
							ans[1][k] = q.front(), q.pop();
					for(int k = 0; k < 13; k++)
						if(ans[0][k] == '0')
							ans[0][k] = q.front(), q.pop();
				} else {
					queue<char> q;
					for(int k = q2+1; k < n; k++)
						q.push(s[k]);
					for(int k = 0; k < q1; k++)
						q.push(s[k]);
					for(int k = 13-1; k >= 0; k--)
						if(ans[1][k] == '0')
							ans[1][k] = q.front(), q.pop();
					for(int k = 0; k < 13; k++)
						if(ans[0][k] == '0')
							ans[0][k] = q.front(), q.pop();
				}
				for(int p = 0; p < 2; p++,cout<<"\n")
					for(int q = 0; q < 13; q++)
						cout << ans[p][q];
				return 0;
			}
	return cout<<"Impossible",0;
}