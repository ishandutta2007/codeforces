#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
#define rep(i,a,b) for(int i = int(a); i < (b); ++i)
#define rrep(i,a,b) for(int i = int(b)-1; i >= int(a); --i)
typedef vector<int> vi;

const int maxn = 500100;
vi nums, rnums;
vector<vi> barn;
int ix = 0, rix = 0;

void f(int a){
	nums[a] = ix++;
	for(int b : barn[a])
		f(b);
	rnums[a] = rix++;
}

int main(){
	int n,m;
	char s[maxn];
	scanf("%d%d",&n,&m);
	nums.resize(n), rnums.resize(n);
	barn.resize(n);
	vector<vi> hlist(n);
	vector<vi> cumsum(n,vi(1,0));
	rep(i,1,n){
		int p;
		scanf("%d",&p);
		barn[p-1].push_back(i);
	}
	f(0);
	scanf(" %s ",s);
	hlist[0].push_back(0);
	rep(i,1,n)
		for(int p : hlist[i-1])
			for(int b : barn[p])
				hlist[i].push_back(b),
				cumsum[i].push_back(cumsum[i].back()^(1<<(s[b]-'a')));
	rep(i,0,m){
		int v,h;
		scanf("%d%d",&v,&h);
		--v,--h;
		int a = -1, b = hlist[h].size();
		while(a+1 < b){
			int m = (a+b)/2;
			if(nums[hlist[h][m]] >= nums[v])
				b = m;
			else
				a = m;
		}
		int l = a+1;
		a = -1, b = hlist[h].size();
		while(a+1 < b){
			int m = (a+b)/2;
			if(rnums[hlist[h][m]] >= rnums[v])
				b = m;
			else
				a = m;
		}
		int u = a+1;
		int bs = u <= l ? 0 : cumsum[h][l] ^ cumsum[h][u];
		int cnt = 0;
		rep(i,0,27)
			cnt += (bs&(1<<i)) != 0;
		printf(cnt <= 1 ? "Yes\n" : "No\n");
	}
}