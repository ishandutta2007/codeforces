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
 
char s[N];
int n;
vector< int > ans;
int main()
{
	scanf("%s", s);
	n = strlen(s);
	int j = n - 1;
	for(int i = 0; i < n; i++){
		if(s[i] == '('){
			while(j > i && s[j] != ')')
				j--;
			if(i >= j){
				break;	
			}         
			ans.pb(i);
			ans.pb(j);
			j--;
		}
	}
	if(ans.empty()){
		printf("0");
	}else{
		printf("1\n");
		sort(ans.begin(), ans.end());
		printf("%d\n", ans.size());
		for(auto it : ans)
			printf("%d ", it + 1);
	}
}