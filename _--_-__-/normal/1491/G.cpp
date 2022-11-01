#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a[200005];
bool vis[200005];
vector<PII> ans;

void solve2(vector<int> A, const vector<int> B)
{
	for(int i = (int)A.size() - 1; i >= 0; i --) ans.push_back(MP(A[i], B[0]));
	for(int i = (int)B.size() - 1; i >= 0; i --) ans.push_back(MP(A.back(), B[i]));
}
void solve1(vector<int> A)
{
	rotate(A.begin(), A.end() - 2, A.end() - 1);
	for(int i = (int)A.size() - 2; i >= 0; i --) ans.push_back(MP(A[i], A.back()));
	ans.push_back(MP(A[A.size() - 2], A[0]));
	ans.push_back(MP(A[A.size() - 2], A.back()));
}

int cnt;
vector<int> cys[200005];

int main()
{
	scanf("%d", &n);
	rep1(i, n) scanf("%d", &a[i]);
	
	rep1(i, n) if(!vis[i]) {
		int j = i;
		do {
			cys[cnt].push_back(j);
			vis[j] = true; j = a[j];
		} while(j != i);
		reverse(cys[cnt].begin(), cys[cnt].end());
		cnt ++;
	}
	
	if(cnt != 1 && (cnt & 1)) cys[cnt ++].push_back(cys[0][0]);
	rep(i, cnt) if(i + 1 < cnt) {
		solve2(cys[i], cys[i + 1]); i ++;
	} else solve1(cys[i]);
	
	printf("%d\n", ans.size());
	rep(i, ans.size()) printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}