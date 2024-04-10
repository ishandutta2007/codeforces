#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int main()
{
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int cnt = 0;
		set<char>st;
		for(int i = 0; i <= s.size(); i++)
			if(i < s.size() && (i == 0 || s[i] == s[i - 1]))
				cnt++;
			else{
				if(cnt & 1)
					st.insert(s[i - 1]);
				cnt = 1;
			}
		for(auto it : st)
			cout << it;
		cout << endl;				
	}
	return 0;
}