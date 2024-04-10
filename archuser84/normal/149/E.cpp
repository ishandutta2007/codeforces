///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;

const int N = 1e5+1e3+10;
const int M = 110;
string S, t, s;
int a[N], b[N];
int n, m;

void kmp(int* a){
	a[0] = 0;
	Loop(i,1,s.size()){
		a[i] = a[i-1]+1;
		while(a[i]>1 && s[i] != s[a[i]-1])
			a[i] = a[a[i]-2]+1;
		if(a[i] && s[i] != s[a[i]-1]) a[i] = 0;
	}
}

bool good(){
	if(t.size()==1) return 0;
	s = t + "#" + S;
	kmp(a);
	reverse(s.begin(), s.begin()+t.size());
	reverse(s.begin()+t.size()+1, s.end());
	kmp(b);
	reverse(b+t.size()+1, b+s.size());
	LoopR(i,0,s.size()-1) b[i] = max(b[i], b[i+1]);
	Loop(i,t.size()+1,s.size()-1)
		if(a[i]+b[i+1] >= t.size()){
			return 1;
		}
	return 0;
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> S >> m;
	int ans=  0;
	while(m--){
		cin >> t;
		ans += good();
	}
	cout << ans << '\n';
}