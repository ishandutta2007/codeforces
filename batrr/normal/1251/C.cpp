#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)5e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

char s[N];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		int n = strlen(s);
		vector< int > v[2];
		for(int i = 0; i < n; i++)
			v[(s[i] - '0') & 1].pb(s[i] - '0');
		int i = 0, j = 0;
		while(i < v[0].size() || j < v[1].size()){
			if(i == v[0].size())
				printf("%d", v[1][j++]);
			else if(j == v[1].size())
				printf("%d", v[0][i++]);
			else if(v[0][i] < v[1][j])
				printf("%d", v[0][i++]);
			else
				printf("%d", v[1][j++]);
		}
		printf("\n");
	}
	return 0;
}