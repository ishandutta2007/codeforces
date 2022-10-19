// i hate data structure
#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")

constexpr int SZ = 1 << 20;

class INPUT {
private:
    char read_buf[SZ];
    int read_idx, next_idx;
    bool __END_FLAG__, __GETLINE_FLAG__;
public:
    explicit operator bool() { return !__END_FLAG__; }
    bool IsBlank(char c) { return c == ' ' || c == '\n'; }
    bool IsEnd(char c) { return c == '\0'; }
    char _ReadChar() {
        if (read_idx == next_idx) {
            next_idx = fread(read_buf, sizeof(char), SZ, stdin);
            if (next_idx == 0) return 0;
            read_idx = 0;
        }
        return read_buf[read_idx++];
    }
    char ReadChar() {
        char ret = _ReadChar();
        for (; IsBlank(ret); ret = _ReadChar());
        return ret;
    }
    template<typename T> T ReadInt() {
        T ret = 0; char cur = _ReadChar(); bool flag = 0;
        for (; IsBlank(cur); cur = _ReadChar());
        if (cur == '-') flag = 1, cur = _ReadChar();
        for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret = 10 * ret + (cur & 15);
        if (IsEnd(cur)) __END_FLAG__ = 1;
        return flag ? -ret : ret;
    }
    string ReadString() {
        string ret; char cur = _ReadChar();
        for (; IsBlank(cur); cur = _ReadChar());
        for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
        if (IsEnd(cur)) __END_FLAG__ = 1;
        return ret;
    }
    double ReadDouble() {
        string ret = ReadString();
        return stod(ret);
    }
    string getline() {
        string ret; char cur = _ReadChar();
        for (; cur != '\n' && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
        if (__GETLINE_FLAG__) __END_FLAG__ = 1;
        if (IsEnd(cur)) __GETLINE_FLAG__ = 1;
        return ret;
    }
    friend INPUT& getline(INPUT& in, string& s) { s = in.getline(); return in; }
} _in;

class OUTPUT {
private:
    char write_buf[SZ];
    int write_idx;
public:
    ~OUTPUT() { Flush(); }
    explicit operator bool() { return 1; }
    void Flush() {
        fwrite(write_buf, sizeof(char), write_idx, stdout);
        write_idx = 0;
    }
    void WriteChar(char c) {
        if (write_idx == SZ) Flush();
        write_buf[write_idx++] = c;
    }
    template<typename T> int GetSize(T n) {
        int ret = 1;
        for (n = n >= 0 ? n : -n; n >= 10; n /= 10) ret++;
        return ret;
    }
    template<typename T> void WriteInt(T n) {
        int sz = GetSize(n);
        if (write_idx + sz >= SZ) Flush();
        if (n < 0) write_buf[write_idx++] = '-', n = -n;
        for (int i = sz; i-- > 0; n /= 10) write_buf[write_idx + i] = n % 10 | 48;
        write_idx += sz;
    }
    void WriteString(string s) { for (auto& c : s) WriteChar(c); }
    void WriteDouble(double d) { WriteString(to_string(d)); }
} _out;

/* operators */
INPUT& operator>> (INPUT& in, char& i) { i = in.ReadChar(); return in; }
INPUT& operator>> (INPUT& in, string& i) { i = in.ReadString(); return in; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
INPUT & operator>> (INPUT& in, T& i) {
    if constexpr (is_floating_point_v<T>) i = in.ReadDouble();
    else if constexpr (is_integral_v<T>) i = in.ReadInt<T>(); return in;
}

OUTPUT& operator<< (OUTPUT& out, char i) { out.WriteChar(i); return out; }
OUTPUT& operator<< (OUTPUT& out, string i) { out.WriteString(i); return out; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
OUTPUT & operator<< (OUTPUT& out, T i) {
    if constexpr (is_floating_point_v<T>) out.WriteDouble(i);
    else if constexpr (is_integral_v<T>) out.WriteInt<T>(i); return out;
}

/* macros */
#define fastio 1
#define cin _in
#define cout _out
#define istream INPUT
#define ostream OUTPUT
/////////////////////////////////////////////////////////////////////////////////////////////
#endif
const int N = 150015, B = 70, M = (N + B - 1) / B * B + 10;
int n, a[N], pos[N];
namespace sqrtDecomp {
	bool used[N];
	int vl[N], vr[N];
	struct data {
		vector<pair<int, signed char>> vec; // (val, cnt)
		int sum, add, chk;
		signed char cnt;
		void out() {
			printf("sum: %d cnt: %d add: %d chk: %d\n", sum, cnt, add, chk);
			for(auto x : vec) printf("(%d %d)\n", x.fi, x.se);
		}
	} pl[M], pr[M];
	int getid(int l) {return (l + B - 1) / B;}
	void init() {
		rep(i, 1, getid(n)) pl[i].chk = 0, pr[i].chk = n + 1;
	}
	int getl(int id) {return (id - 1) * B + 1;}
	void pushdown(int id) {
		int l = getl(id), r = min(n, l + B - 1);
		int &al = pl[id].add, &ar = pr[id].add, &ml = pl[id].chk, &mr = pr[id].chk;
		rep(i, l, r) if(used[i]) vl[i] = max(vl[i] + al, ml), vr[i] = min(vr[i] + ar, mr);
		al = ar = 0;
		ml = -1; mr = n + 1;
	}
	signed char bucket[N];
	void rebuild(int id) {
		int l = getl(id), r = min(n, l + B - 1);
		// printf("rebuild [%d %d]\n", l, r);
		int &sl = pl[id].sum, &sr = pr[id].sum;
		auto &cnt = pl[id].cnt;
		sl = sr = cnt = 0;
		rep(i, l, r) if(used[i]) sl += vl[i], sr += vr[i], cnt++;

		rep(i, l, r) if(used[i]) bucket[vl[i]]++;
		pl[id].vec.clear();
		rep(i, l, r) if(bucket[vl[i]]) pl[id].vec.emplace_back(vl[i], bucket[vl[i]]), bucket[vl[i]] = 0;
		sort(all(pl[id].vec), [&] (auto u, auto v) {
			return u.fi > v.fi;
		});

		rep(i, l, r) if(used[i]) bucket[vr[i]]++;
		pr[id].vec.clear();
		rep(i, l, r) if(bucket[vr[i]]) pr[id].vec.emplace_back(vr[i], bucket[vr[i]]), bucket[vr[i]] = 0;
		sort(all(pr[id].vec), [&] (auto u, auto v) {
			return u.fi < v.fi;
		});
	}
	void Cmin(int id, int v) {
		int &sr = pr[id].sum, &add = pr[id].add;
		signed char cnt = 0;
		while(SZ(pr[id].vec) > 0 && pr[id].vec.back().fi + add >= v) {
			int p, q; tie(p, q) = pr[id].vec.back(); pr[id].vec.pop_back();
			p += add;
			cnt += q;
			sr -= p * q;
		}
		if(cnt > 0) pr[id].vec.emplace_back(v - add, cnt), sr += v * cnt;
		pr[id].chk = min(pr[id].chk, v);
	}
	void cmin(int l, int r, int v) {
		int L = getid(l), R = getid(r);
		if(L == R) {
			pushdown(L);
			rep(i, l, r) vr[i] = min(vr[i], v);
			rebuild(L);
		} else {
			rep(i, L + 1, R - 1) Cmin(i, v);
			pushdown(L); pushdown(R);
			rep(i, l, L * B) vr[i] = min(vr[i], v);
			rep(i, (R - 1) * B + 1, r) vr[i] = min(vr[i], v);
			rebuild(L); rebuild(R);
		}
	}
	void Cmax(int id, int v) {
		int &sl = pl[id].sum, &add = pl[id].add;
		signed char cnt = 0;
		while(SZ(pl[id].vec) > 0 && pl[id].vec.back().fi + add <= v) {
			int p, q; tie(p, q) = pl[id].vec.back(); pl[id].vec.pop_back();
			p += add;
			cnt += q;
			sl -= p * q;
		}
		if(cnt > 0) pl[id].vec.emplace_back(v - add, cnt), sl += v * cnt;
		pl[id].chk = max(pl[id].chk, v);
	}
	void cmax(int l, int r, int v) {
		int L = getid(l), R = getid(r);
		if(L == R) {
			pushdown(L);
			rep(i, l, r) vl[i] = max(vl[i], v);
			rebuild(L);
		} else {
			rep(i, L + 1, R - 1) Cmax(i, v);
			pushdown(L); pushdown(R);
			rep(i, l, L * B) vl[i] = max(vl[i], v);
			rep(i, (R - 1) * B + 1, r) vl[i] = max(vl[i], v);
			rebuild(L); rebuild(R);
		}
	}
	void add(int l, int r, int v) {
		int L = getid(l), R = getid(r);
		if(L == R) {
			pushdown(L);
			rep(i, l, r) if(used[i]) vl[i]++, vr[i]++;
			rebuild(L);
		} else {
			rep(i, L + 1, R - 1) {
				pl[i].add++; pr[i].add++;
				pl[i].sum += pl[i].cnt; pr[i].sum += pl[i].cnt;
				pl[i].chk++; pr[i].chk++;
			}
			pushdown(L); pushdown(R);
			rep(i, l, L * B) if(used[i]) vl[i]++, vr[i]++;
			rep(i, (R - 1) * B + 1, r) if(used[i]) vl[i]++, vr[i]++;
			rebuild(L); rebuild(R);
		}
	}
	void modify(int p, int l, int r) {
		int P = getid(p);
		pushdown(P);
		used[p] = 1;
		vl[p] = l; vr[p] = r;
		rebuild(P);
	}
	int qcnt(int l, int r) {
		int L = getid(l), R = getid(r), res = 0;
		if(L == R) {
			rep(i, l, r) if(used[i]) res++;
		} else {
			rep(i, L + 1, R - 1) res += pl[i].cnt;
			rep(i, l, L * B) if(used[i]) res++;
			rep(i, (R - 1) * B + 1, r) if(used[i]) res++;
		}
		return res;
	}
}
using namespace sqrtDecomp;
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	#ifndef ONLINE_JUDGE
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	#endif
	cin >> n;
	init();
	rep(i, 1, n) cin >> a[i], pos[a[i]] = i;
	auto Debug = [&](int i) -> void{
		// printf("------*** %d ***-----\n", i);
		// rep(i, 1, getid(n)) {
		// 	printf("IIIIIII %d\n", i);
		// 	printf("pl\n"); pl[i].out();
		// 	printf("pr\n"); pr[i].out();
		// }
		// rep(i, 1, n) if(used[i]) printf("[%d %d]\n", vl[i], vr[i]);
	};
	rep(_, 1, n) {
		int p = pos[_], rk = qcnt(1, p) + 1;
		modify(p, 0, _ + 1);
		// Debug(1);
		if(p > 1) cmin(1, p - 1, rk);
		// Debug(2);
		if(p < n) add(p + 1, n, 1);
		// Debug(3);
		if(p < n) cmax(p + 1, n, rk);
		Debug(4);
		ll ans = 0;
		rep(i, 1, getid(n)) ans += pr[i].sum - pl[i].sum;
		cout << ans - _ << '\n';
	}
	return 0;
}