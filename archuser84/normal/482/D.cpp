#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int mod = 1e9+7;
const int N = 100'010;
vector<int> A[N];
int n;

pll dfs(int v)
{
	pll ans = {0, 1};
	ll ev = 1;
	pll od = {1, 0};
	for (int u : A[v]) {
		pll ansu = dfs(u);
		ev = (ev * ansu.first) % mod;
		pll tmp;
		tmp.first = (ans.first*ansu.first + ans.second*ansu.second) % mod;
		tmp.second = (ans.first*ansu.second + ans.second*ansu.first) % mod;
		ans = tmp;
		tmp.first = (od.first + od.second*ansu.second) % mod;
		tmp.second = (od.second + od.first*ansu.second) % mod;
		od = tmp;
	}
	ans.first *= 2;
	ans.first -= od.second;
	ans.first += 1;
	ans.first %= mod;
	ans.second *= 2;
	ans.second -= ev;
	ans.second %= mod;
	return ans;
}

pll heap_dfs(int);
asm("\n"
"	.bss\n"
"	.p2align 12\n"
"myhb:	.zero 0x1000000\n"
"myhe:\n"
"	.text\n"
"_Z8heap_dfsi:\n"
"	mov	%rsp, %rax\n"
"	lea	myhe(%rip), %rsp\n"
"	push	%rax\n"
"	push	%rbp\n"
"	mov	%rsp, %rbp\n"
"	call	_Z3dfsi\n"
"	pop	%rbp\n"
"	pop	%rsp\n"
"	ret\n"
);

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop (i,1,n) {
		int p;
		cin >> p;
		A[p-1].push_back(i);
	}
	auto tmp = heap_dfs(0);
	ll ans = tmp.first + tmp.second - 1;
	ans = (ans%mod+mod)%mod;
	cout << ans << '\n';
}