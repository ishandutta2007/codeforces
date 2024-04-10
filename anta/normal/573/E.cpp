#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>

#ifdef MY_LOCAL_RUN
#include <nmmintrin.h>
#endif

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

#ifdef MY_LOCAL_RUN

__declspec(noinline) void __cdecl solve(long long *dp, const int *a, int n) {
	rep(i, n) {
		int t = a[i];
		int j = i;
		ll ttt[2] = { t * 2, t * 2 };
		__m128i tt = _mm_loadu_si128((const __m128i*)ttt);
		ll u[2] = { (ll)t * i, (ll)t * (i+1) };
		__m128i c = _mm_loadu_si128((const __m128i*)u);
		for(; j >= 1; j -= 2) {
			__m128i a = _mm_loadu_si128((const __m128i*)(dp + (j-1)));
			__m128i x = _mm_add_epi64(a, c);
			__m128i y = _mm_loadu_si128((const __m128i*)(dp + j));
			__m128i mask = _mm_cmpgt_epi64(y, x);
			__m128i z = _mm_blendv_epi8(x, y, mask);
			_mm_storeu_si128((__m128i*)(dp + j), z);
			c = _mm_sub_epi64(c, tt);
		}
		for(; j >= 0; -- j)
			amax(dp[j+1], dp[j] + (ll)t * (j+1));
 	}
}
#else
__declspec(noinline) void __cdecl solve(long long *dp, const int *a, int n) {
__asm(
"L99FB2809:\n"
"	\n"
"	pushl	%ebp\n"
"	\n"
"	\n"
"	pushl	%edi\n"
"	\n"
"	\n"
"	pushl	%esi\n"
"	\n"
"	\n"
"	pushl	%ebx\n"
"	\n"
"	\n"
"	subl	$64, %esp\n"
"	\n"
"	movl	92(%esp), %eax\n"
"	movl	84(%esp), %edi\n"
"	testl	%eax, %eax\n"
"	jle	L992\n"
"	leal	-8(%edi), %eax\n"
"	xorl	%ebp, %ebp\n"
"	movl	%eax, 12(%esp)\n"
"	movl	$0, 4(%esp)\n"
"	movl	$0, 8(%esp)\n"
"	.p2align 4,,7\n"
"L9911:\n"
"	movl	88(%esp), %eax\n"
"	movl	8(%esp), %esi\n"
"	movl	%ebp, 16(%esp)\n"
"	movl	(%eax,%ebp,4), %eax\n"
"	leal	(%eax,%eax), %ecx\n"
"	movl	%eax, %edx\n"
"	movl	%ecx, %ebx\n"
"	sarl	$31, %ebx\n"
"	movl	%ecx, 20(%esp)\n"
"	imull	%edx, %esi\n"
"	movl	%ebx, 24(%esp)\n"
"	movl	%ecx, 28(%esp)\n"
"	movl	%eax, %ecx\n"
"	movl	%ebx, 32(%esp)\n"
"	movl	%eax, %ebx\n"
"	movl	4(%esp), %eax\n"
"	sarl	$31, %ebx\n"
"	movdqu	20(%esp), %xmm4\n"
"	movl	%edx, (%esp)\n"
"	imull	%ebx, %eax\n"
"	leal	(%eax,%esi), %esi\n"
"	movl	(%esp), %eax\n"
"	mull	4(%esp)\n"
"	addl	%esi, %edx\n"
"	movl	%eax, 36(%esp)\n"
"	movl	4(%esp), %eax\n"
"	movl	%edx, 40(%esp)\n"
"	movl	8(%esp), %edx\n"
"	addl	$1, %eax\n"
"	adcl	$0, %edx\n"
"	movl	%eax, %esi\n"
"	movl	%edx, 8(%esp)\n"
"	movl	8(%esp), %edx\n"
"	imull	%ebx, %esi\n"
"	imull	(%esp), %edx\n"
"	movl	%eax, 4(%esp)\n"
"	movl	(%esp), %eax\n"
"	leal	(%esi,%edx), %esi\n"
"	mull	4(%esp)\n"
"	addl	%esi, %edx\n"
"	testl	%ebp, %ebp\n"
"	movl	%eax, 44(%esp)\n"
"	movl	%edx, 48(%esp)\n"
"	movdqu	36(%esp), %xmm1\n"
"	je	L994\n"
"	movl	12(%esp), %eax\n"
"	movl	%ebp, %esi\n"
"	.p2align 4,,7\n"
"L996:\n"
"	movdqu	(%eax), %xmm2\n"
"	subl	$2, %esi\n"
"	paddq	%xmm1, %xmm2\n"
"	movdqu	8(%eax), %xmm3\n"
"	subl	$16, %eax\n"
"	movdqa	%xmm3, %xmm0\n"
"	pcmpgtq	%xmm2, %xmm0\n"
"	pblendvb	%xmm0, %xmm3, %xmm2\n"
"	movdqu	%xmm2, 24(%eax)\n"
"	testl	%esi, %esi\n"
"	psubq	%xmm4, %xmm1\n"
"	jg	L996\n"
"	leal	-1(%ebp), %eax\n"
"	andl	$-2, %eax\n"
"	leal	-2(%ebp), %edx\n"
"	cmpl	%eax, %edx\n"
"	jne	L997\n"
"L994:\n"
"	movl	%ecx, %eax\n"
"	movl	%ebx, %edx\n"
"	addl	(%edi), %eax\n"
"	adcl	4(%edi), %edx\n"
"	cmpl	12(%edi), %edx\n"
"	jge	L9918\n"
"L997:\n"
"	addl	$1, %ebp\n"
"	addl	$8, 12(%esp)\n"
"	cmpl	92(%esp), %ebp\n"
"	jne	L9911\n"
"L992:\n"
"	addl	$64, %esp\n"
"	\n"
"	\n"
"	popl	%ebx\n"
"	\n"
"	\n"
"	popl	%esi\n"
"	\n"
"	\n"
"	popl	%edi\n"
"	\n"
"	\n"
"	popl	%ebp\n"
"	\n"
"	\n"
"	ret\n"
"	.p2align 4,,7\n"
"L9918:\n"
"	\n"
"	jg	L9912\n"
"	cmpl	8(%edi), %eax\n"
"	.p2align 4,,2\n"
"	jbe	L997\n"
"L9912:\n"
"	movl	%eax, 8(%edi)\n"
"	movl	%edx, 12(%edi)\n"
"	.p2align 4,,2\n"
"	jmp	L997\n"
"	\n"
"\n"
);
}

#endif

int main(int argc, char **argv) {
	int n;
	while(~scanf("%d", &n)) {
		vi a(n);
		rep(i, n) {
			scanf("%d", &a[i]);
		}
		long long *dp = new long long[n + 2];
		rep(i, n+2) dp[i] = -INFL;
		dp[0] = 0;
		solve(dp, &a[0], n);
		long long ans = *max_element(dp, dp + (n+1));
		cout << ans << endl;
	}
	return 0;
}