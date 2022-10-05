#include <bits/stdc++.h>
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/
#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=2e5+12,inf=1e9,mod=1e9+7,LOG=18;

int n, N, ans;
bool mark[128];
int ar[128][128];
string s;

int augpath(int node, int flow) {
	if (node == N - 1) 
		return flow;
	mark[node] = true;
	for (int i = 0; i < N; i++)
 	if (!mark[i] && ar[node][i]) {
		int tmp = augpath(i, min(flow, ar[node][i]));
		if (!tmp) continue;
		ar[node][i] -= tmp;
		ar[i][node] += tmp;
		return tmp;
	}	
	return 0;
}

int main() {
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
	#endif                                     

	cin>>s;
	cin>>n;
	N = n + 28;
	for (int i = 0; i < s.size(); i++) 
		ar[s[i] - 'a' + n + 1][N - 1]++;
	for (int i = 0; i < n; i++) {
		cin>>s;
		cin>>ar[0][i+1];
		
		for (int j = 0; j < s.size(); j++) 
			ar[i + 1][s[j] - 'a' + n + 1]++;	
	}
 	while (1) {
		int flow = augpath(0, inf);
		if (!flow) 
			break;
		for (int i = 0; i < N - 1; i++) 
			mark[i] = false;
	}
	for (int i = 1; i <= n; i++)
    	for (int j = n + 1; j <= n + 26; j++) 
    		ans += i * ar[j][i];
	for (int i = n + 1; i <= n + 26; i++)
    	if (ar[i][N - 1]) ans = -1;
	printf("%d\n", ans);
}