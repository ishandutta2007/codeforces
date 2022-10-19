///
///   Oh? You're approaching me?
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

__attribute((naked))
unsigned short *extract(unsigned short*, unsigned short*, size_t)
{
	asm(
	".intel_syntax noprefix\n\t"
#ifdef _WIN32 // microsoft hates unix
	"push rdi\n\t"
	"push rsi\n\t"
	"mov rdi, rcx\n\t"
	"mov rsi, rdx\n\t"
	"mov rdx, r8\n\t"
#endif
	"lea rdx, [rsi+2*rdx]\n\t"
	"vpxor ymm0, ymm0, ymm0\n\t"
	"vpcmpeqb ymm0, ymm0, ymm0\n\t"

"my_extract_loop:\n\t"
	"vmovaps ymm1, [rsi]\n\t"
	"add rsi, 32\n\t"
	"vpcmpeqw ymm2, ymm1, ymm0\n\t"
	"vpcmpgtw ymm2, ymm2, ymm0\n\t"
	"vextracti128 xmm3, ymm1, 1\n\t"
	"vextracti128 xmm4, ymm2, 1\n\t"

	"pextrq rax, xmm1, 0\n\t"
	"pextrq rcx, xmm2, 0\n\t"
	"pext rax, rax, rcx\n\t"
	"mov [rdi], rax\n\t"
	"popcnt rcx, rcx\n\t"
	"shr rcx, 3\n\t"
	"add rdi, rcx\n\t"

	"pextrq rax, xmm1, 1\n\t"
	"pextrq rcx, xmm2, 1\n\t"
	"pext rax, rax, rcx\n\t"
	"mov [rdi], rax\n\t"
	"popcnt rcx, rcx\n\t"
	"shr rcx, 3\n\t"
	"add rdi, rcx\n\t"

	"pextrq rax, xmm3, 0\n\t"
	"pextrq rcx, xmm4, 0\n\t"
	"pext rax, rax, rcx\n\t"
	"mov [rdi], rax\n\t"
	"popcnt rcx, rcx\n\t"
	"shr rcx, 3\n\t"
	"add rdi, rcx\n\t"

	"pextrq rax, xmm3, 1\n\t"
	"pextrq rcx, xmm4, 1\n\t"
	"pext rax, rax, rcx\n\t"
	"mov [rdi], rax\n\t"
	"popcnt rcx, rcx\n\t"
	"shr rcx, 3\n\t"
	"add rdi, rcx\n\t"

	"cmp rsi, rdx\n\t"
	"jne my_extract_loop\n\t"

	"mov rax, rdi\n\t"
#ifdef _WIN32
	"pop rsi\n\t"
	"pop rdi\n\t"
#endif
	"ret\n\t"
	".att_syntax\n\t"
	);
}

const int N = 100032;
const int N2 = N/2;
const int C = 4000;
const int M = 26;
unsigned short dard[M][N];
unsigned short dard2[N];
unsigned short cur[N], ecur[N];
int cm, cn;
string s, t[N]; int k[N];
int ord[N], ans[N];
int n, m, q;

__attribute((optimize("O3,unroll-loops,no-tree-loop-distribute-patterns"),target("avx2")))
void makecur(int i)
{
	int m = t[i].size(), c;

	c = t[i][0]-'a';
	Loop (k,0,N-m+1)
		cur[k] = dard[c][k];
	for (int l = 0; l < N-m+1; l += C) {
		int r = min(l+C, N-m+1);
		for (int j = 1; j + 3 <= m; j += 3) {
			unsigned short c1 = t[i][j]-'a';
			unsigned short c2 = t[i][j+1]-'a';
			unsigned short c3 = t[i][j+2]-'a';
			Loop (k,l,r) {
				unsigned short tmp1 = dard2[k+j];
				cur[k] |= -(tmp1 != c1);
				unsigned short tmp2 = dard2[k+j+1];
				cur[k] |= -(tmp2 != c2);
				unsigned short tmp3 = dard2[k+j+2];
				cur[k] |= -(tmp3 != c3);
			}
		}
		if (m%3 == 0) {
			unsigned short c1 = t[i][m-2]-'a';
			unsigned short c2 = t[i][m-1]-'a';
			Loop (k,l,r) {
				unsigned short tmp1 = dard2[k+m-2];
				cur[k] |= -(tmp1 != c1);
				unsigned short tmp2 = dard2[k+m-1];
				cur[k] |= -(tmp2 != c2);
			}
		}
		if (m%3 == 2) {
			unsigned short c1 = t[i][m-1]-'a';
			Loop (k,l,r) {
				unsigned short tmp1 = dard2[k+m-1];
				cur[k] |= -(tmp1 != c1);
			}
		}
	}
	int r = N-m+1;
	while (r&15)
		cur[r++] = -1;
	if (r > N2) {
		cm = extract(ecur, cur, N2) - ecur;
		cn = extract(ecur+cm, cur+N2, r-N2) - ecur;
	} else {
		cm = cn = extract(ecur, cur, r) - ecur;
	}
}

#define min(x, y) ((x)<(y)?(x):(y))
#define max(x, y) ((x)>(y)?(x):(y))

__attribute((optimize("O3,unroll-loops"),target("avx2")))
int get(int k)
{
	int ans = N, r, l;
	unsigned short x, xx;

	l = 0; r = max(0, cm - k); x = 65535;
	Loop (i,l,r) {
		unsigned short y = ecur[i+k] - ecur[i];
		x = min(x, y);
	}
	if (x != 65535)
		ans = min(ans, x);

	l = max(0, cm - k); r = min(cm, cn - k); x = xx = 65535;
	Loop (i,l,r) {
		unsigned short y2 = ecur[i+k] - ecur[i];
		unsigned short y1 = N2 + y2;
		unsigned short a1 = -(ecur[i+k] > ecur[i]);
		unsigned short a2 = ~a1;
		x = min(x, y1|a1);
		xx = min(xx, y2|a2);
	}
	if (x != 65535)
		ans = min(ans, x);
	if (xx != 65535)
		ans = min(ans, N2+xx);

	l = min(cm, cn - k); r = cn - k; x = 65535;
	Loop (i,l,r) {
		unsigned short y = ecur[i+k] - ecur[i];
		x = min(x, y);
	}
	if (x != 65535)
		ans = min(ans, x);

	return ans;
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	memset(dard, -1, sizeof(dard));
	memset(dard2, -1, sizeof(dard2));
	cin >> s >> q;
	n = s.size();
	Loop (i,0,n) {
		dard[s[i]-'a'][i] = i%N2;
		dard2[i] = s[i] - 'a';
	}
	Loop (i,0,q)
		cin >> k[i] >> t[i];
	iota(ord, ord+q, 0);
	sort(ord, ord+q, [&](int a, int b){
		return t[a][0] < t[b][0]
		       || (t[a][0] == t[b][0] && t[a][1] < t[b][1]);
	});
	Loop (ii,0,q) {
		int i = ord[ii];
		if (!ii || t[ord[ii-1]] != t[i])
			makecur(i);
		ans[i] = get(k[i]-1) + t[i].size();
	}
	Loop (i,0,q)
		cout << (ans[i]<N? ans[i]: -1) << '\n';
}