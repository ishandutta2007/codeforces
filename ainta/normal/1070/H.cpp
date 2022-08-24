#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,n) for(int i=1;i<=n;i++)

int n;
string S[10100];
char p[110];
map<string,int>Map, Map2, C;

int main() {
	int i, j, k;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%s",p);
		S[i] = p;
	}
	for(i=1;i<=n;i++){
		int sz = S[i].size();
		Map2.clear();
		for(j=0;j<sz;j++){
			string t = "";
			for(k=j;k<sz;k++){
				t+=S[i][k];
				Map2[t] = 1;
			}
		}
		for(auto &t : Map2){
			C[t.first]++;
			Map[t.first] = i;
		}
	}
	int  Q;
	scanf("%d",&Q);
	while(Q--){
		scanf("%s",p);
		if(!Map.count(p))printf("0 -\n");
		else printf("%d %s\n",C[p], S[Map[p]].c_str());
	}
}