#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MAXN = 105;

int T,R,C,K;
char b[MAXN][MAXN],ans[MAXN][MAXN];
vector<char> v;

int main() {
	boost();
	for(int i=0; i<=9; i++) v.push_back((char)(i+'0'));
	for(int i=0; i<26; i++){
		v.push_back((char)(i+'a'));
		v.push_back((char)(i+'A'));
	}
	cin>>T;
	while(T--){
		cin>>R>>C>>K;
		int sum = 0;
		for(int i=1; i<=R; i++){
			for(int k=1; k<=C; k++){
				cin>>b[i][k];
				if(b[i][k] == 'R')
					sum++;
			}
		}
		int each = sum/K;
		int rem = sum%K;
		int curr = 0, chick = 0;
		for(int i=1; i<=R; i++){
			int start = (i%2==1?1:C);
			int re = (i%2==1?C:1);
			for(int k=start; k!=re; k+=(i%2==1?1:-1)){
				if(b[i][k] == 'R'){
					curr++;
					ans[i][k] = v[chick];
					if(curr == each+1 && rem){
						curr = 0;
						chick++;
						if(chick >= K) chick--;
						rem--;
					}else if(curr == each && rem == 0){
						curr = 0;
						chick++;
						if(chick >= K) chick--;
					}
				}else ans[i][k] = v[chick];
			}
			if(b[i][re] == 'R'){
				curr++;
				ans[i][re] = v[chick];
				if(curr == each+1 && rem){
					curr = 0;
					chick++;
					rem--;
					if(chick >= K) chick--;
				}else if(curr == each && rem == 0){
					curr = 0;
					chick++;
					if(chick >= K) chick--;
				}
			}else ans[i][re] = v[chick];
		}
		for(int i=1; i<=R; i++){
			for(int k=1; k<=C; k++){
				cout<<ans[i][k];
			}
			cout<<endl;
		}
	}

	return 0;
}