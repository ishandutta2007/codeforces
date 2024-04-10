#include<bits/stdc++.h>

using namespace std;

const int maxn=1e6;

int n;
int ile[maxn];

int main()
{
	cin >> n;
	for(int i = 1; i <= n; ++i){
		string s;
		cin >> s;
		for(int j = 0; j < s.size(); ++j)
			ile[j] += s[j] - '0';
	}
	
	int maxi = 0;
	for(int i = 0; i < 7; ++i)
		maxi = max(maxi, ile[i]);
	cout << maxi;
	return 0;
}