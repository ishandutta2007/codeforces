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
using namespace std;

const int N = 1e6+10;
string s;
int n, m;

namespace seg
{
	struct node{
		int cnt4 = 0, cnt7 = 0;
		bool lzy = 0;
		int mx1 = 0, mx2 = 0;
	} t[N<<2];

	void rev(node& v){
		swap(v.cnt4, v.cnt7);
		swap(v.mx1, v.mx2);
		v.lzy ^= 1;
	}

	void ppg(int i){
		if(t[i].lzy){
			rev(t[2*i+1]);
			rev(t[2*i+2]);
			t[i].lzy = 0;
		}
	}

	node merge(const node& a, const node& b){
		node ans;
		ans.cnt4 = a.cnt4 + b.cnt4;
		ans.cnt7 = a.cnt7 + b.cnt7;
		ans.mx1 = max(a.mx1 + b.cnt7, a.cnt4 + b.mx1);
		ans.mx2 = max(a.mx2 + b.cnt4, a.cnt7 + b.mx2);
		return ans;
	}

	void init(int i = 0, int b=0, int e=n){
		if(e-b==1){
			t[i].cnt4 = s[b]=='4';
			t[i].cnt7 = s[b]=='7';
			t[i].mx1 = t[i].mx2 = 1;
			t[i].lzy = 0;
			return;
		}
		init(2*i+1,b,(b+e)/2); init(2*i+2,(b+e)/2,e);
		t[i] = merge(t[2*i+1], t[2*i+2]);
	}

	void up(int l, int r, int i = 0, int b=0, int e=n){
		if(l <= b && e <= r) return rev(t[i]);
		if(r <= b || e <= l) return;
		ppg(i);
		up(l,r,2*i+1,b,(b+e)/2);
		up(l,r,2*i+2,(b+e)/2,e);
		t[i] = merge(t[2*i+1], t[2*i+2]);
	}

	node get(int l, int r, int i = 0, int b=0, int e=n){
		if(l <= b && e <= r) return t[i];
		if(r <= b || e <= l) return node();
		ppg(i);
		return merge(get(l,r,2*i+1,b,(b+e)/2), get(l,r,2*i+2,(b+e)/2,e));
	}
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m >> s;
	seg::init();
	while(m--)
	{
		string s;
		cin >> s;
		if(s[0]=='c') cout << seg::get(0,n).mx1 << '\n';
		if(s[0]=='s'){
			int l, r;
			cin >> l >> r; --l;
			seg::up(l,r);
		}
	}
}