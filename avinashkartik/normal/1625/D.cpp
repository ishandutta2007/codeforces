#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;

const ll   N     =  3e5 + 2;
const ll   mod   =  998244353;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int n, k, a[N];
map <int, int> ind;
vector <int> ans;

template<int N>
struct bitwise_trie {
    struct node {
        int cnt;
        std::array<int, 2> next;
 
        node() : cnt(0) {
            next.fill(-1);
        }
    };
 
    std::vector<node> t;
 
    bitwise_trie() : t(1) {}
 
    void insert(const std::bitset<N> &b, int freq = 1) {
        int cur = 0;
        t[cur].cnt += freq;
        for (int i = N - 1; i >= 0; i--) {
            if (t[cur].next[b[i]] == -1) {
                t[cur].next[b[i]] = (int) t.size();
                t.emplace_back();
            }
            cur = t[cur].next[b[i]];
            t[cur].cnt += freq;
        }
    }
 
    void remove(const std::bitset<N> &b, int freq = 1) {
        insert(b, -freq);
    }
 
    int count(const std::bitset<N> &b) {
        int cur = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (t[cur].next[b[i]] == -1) {
                return 0;
            }
            cur = t[cur].next[b[i]];
        }
        return t[cur].cnt;
    }
 
    std::bitset<N> xor_minimum(std::bitset<N> b) {
        assert(t[0].cnt > 0);
        int cur = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (t[cur].next[b[i]] != -1 && t[t[cur].next[b[i]]].cnt > 0) {
                cur = t[cur].next[b[i]];
                b.reset(i);
            } else {
                cur = t[cur].next[1 ^ b[i]];
                b.set(i);
            }
        }
        return b;
    }
 
    std::bitset<N> xor_maximum(const std::bitset<N> &b) {
        return ~xor_minimum(~b);
    }
 
    node &operator[](int i) {
        return t[i];
    }
};
 
void recurse(int i, vector <int> &v) {
	if (v.size() == 0) return;
	if ((k >> i)&1) {
		bitwise_trie <30> t;
		for (auto it : v) {
			t.insert(a[it]);
		}
		for (auto it : v) {
			bitset <30> b(a[it]);
			int mx = t.xor_maximum(a[it]).to_ulong();
			if (mx >= k) {
				ans.pb(it);
				ans.pb(ind[mx ^ a[it]]);
				return;
			}
		}
		ans.pb(v[0]);
		return;
	} else {
		vector <int> o, z;
		for (auto it : v) {
			if ((a[it] >> i)&1) o.pb(it);
			else z.pb(it);
		}
		recurse(i - 1, o);
		recurse(i - 1, z);
	}
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ind[a[i]] = i;
	}
	vector <int> v(n);
	iota(all(v), 1);
	if (k == 0) {
		deb1(n)
		debv(v)
		return;
	}
	recurse(29, v);
	if (ans.size() >= 2) {
		deb1(ans.size())
		debv(ans)
	} else {
		deb1(-1)
	}
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}