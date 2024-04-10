///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

const int N = 200'010;
const int M = 10;
char s[N], p[M+1];
int n, m, k;

int cnt[1<<19][M][M];
int fst[1<<19], lst[1<<19];
int lzy[1<<19];

void merge(int i)
{
	Loop(x,0,k) Loop(y,0,k)
		cnt[i][x][y]=cnt[2*i+1][x][y]+cnt[2*i+2][x][y];
	cnt[i][lst[2*i+1]][fst[2*i+2]]++;
	fst[i] = fst[2*i+1];
	lst[i] = lst[2*i+2];
}

void tag(int i, int c, int len)
{
	lzy[i] = fst[i] = lst[i] = c;
	Loop(x,0,k) Loop(y,0,k) cnt[i][x][y]=0;
	cnt[i][c][c]=len-1;
}

void ppg(int i, int len)
{
	if(lzy[i]!=-1){
		tag(2*i+1,lzy[i], len   /2);
		tag(2*i+2,lzy[i],(len+1)/2);
		lzy[i]=-1;
	}
}

void init(int i=0, int b=0, int e=n)
{
	lzy[i]=-1;
	if(e-b==1){fst[i]=lst[i]=s[b]; return;}
	init(2*i+1,b,(b+e)/2);
	init(2*i+2,(b+e)/2,e);
	merge(i);
}

void up(int l, int r, int c, int i=0, int b=0, int e=n)
{
	if(l <= b && e <= r) return tag(i,c,e-b);
	if(r <= b || e <= l) return;
	ppg(i,e-b);
	up(l,r,c,2*i+1,b,(b+e)/2);
	up(l,r,c,2*i+2,(b+e)/2,e);
	merge(i);
}

int solve()
{
	int ans = 1;
	Loop(i,0,k) Loop(j,0,i+1)
		ans += cnt[0][p[i]][p[j]];
	return ans;
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m >> k;
	cin >> s; Loop(i,0,n) s[i]-='a';
	init();
	while(m--)
	{
		int t;
		cin >> t;
		if(t==1){
			int l, r; char c;
			cin >> l >> r >> c; --l;
			up(l,r,c-'a');
		} else {
			cin >> p;
			Loop(i,0,k) p[i]-='a';
			cout << solve() << '\n';
		}
	}
}