#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

int n , par[maxn];

string s , res;

void solve(int l , int k)
{
	if(k == 0)
		return;

	int L = l , R = par[l];

	if(R - L + 1 > k)
	{
		solve(l + 1 , k);
		return;
	}

	res += s.substr(L , R - L + 1);
	solve(R + 1 , k - (R - L + 1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int k;
	cin >> n >> k;

	cin >> s;

	stack<int> st;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '(')
			st.push(i);
		else
		{
			par[st.top()] = i;
			par[i] = st.top();
			st.pop();
		}
	}

	solve(0 , k);

	cout << res << endl;
}