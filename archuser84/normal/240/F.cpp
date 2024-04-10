///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

typedef valarray<int> vec;
const int N = 100010;
char s[N];
int n, m;

vec t[N<<2];
char lzy[N<<2];

void tag(int i, char c, int len){t[i]=0; t[i][c] = len; lzy[i] = c;}
void ppg(int i, int len){if(lzy[i]!=-1){tag(2*i+1,lzy[i],len/2);tag(2*i+2,lzy[i],(len+1)/2);lzy[i]=-1;}}

vec get(int l, int r, int i=0, int b=0, int e=N)
{
	if(l <= b && e <= r) return t[i];
	if(r <= b || e <= l) return vec(0,26);
	ppg(i,e-b);
	return get(l,r,2*i+1,b,(b+e)/2)+get(l,r,2*i+2,(b+e)/2,e);
}
void sup(int l, int r, char c, int i=0, int b=0, int e=N)
{
	if(l <= b && e <= r) return tag(i,c,e-b);
	if(r <= b || e <= l) return;
	ppg(i,e-b);
	sup(l,r,c,2*i+1,b,(b+e)/2);
	sup(l,r,c,2*i+2,(b+e)/2,e);
	t[i]=t[2*i+1]+t[2*i+2];
}
void init(int i=0, int b=0, int e=N)
{
	lzy[i]=-1;
	if(e-b==1){t[i]=vec(0,26);t[i][s[b]]=1;return;}
	init(2*i+1,b,(b+e)/2);
	init(2*i+2,(b+e)/2,e);
	t[i]=t[2*i+1]+t[2*i+2];
}

int odd(const vec& cnt){int ans=26; Loop(i,0,26)if(cnt[i]&1)ans=ans==26?i:-1; return ans;}

void up(int l, const vec& cnt)
{
	int o = odd(cnt);
	if(o<0) return;
	int p=l;
	Loop(i,0,26){
		sup(p,p+cnt[i]/2,i);
		p += cnt[i]/2;
	}
	if(o<26) {sup(p,p+1,o);++p;}
	LoopR(i,0,26){
		sup(p,p+cnt[i]/2,i);
		p += cnt[i]/2;
	}
}

int first(const vec& v){Loop(i,0,26)if(v[i])return i; return 26;}

int main()
{
	#ifdef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin.tie(0) -> sync_with_stdio(false);
	#endif
	cin >> n >> m >> s; Loop(i,0,n) s[i]-='a';
	init();
	while(m--)
	{
		int l, r;
		cin >> l >> r; --l;
		auto cnt = get(l,r);
		up(l,cnt);
	}
	Loop(i,0,n) cout << char(first(get(i,i+1))+'a');
	cout << '\n';
}