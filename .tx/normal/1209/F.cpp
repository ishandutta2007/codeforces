#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size()); };
mt19937 rng((size_t) make_shared<char>().get());

#ifndef _LIB_FASTIO_
#define _LIB_FASTIO_

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wconversion"

/** Fast allocation */

#ifdef FAST_ALLOCATOR_MEMORY
	int allocator_pos = 0;
	char allocator_memory[(int)FAST_ALLOCATOR_MEMORY];
	inline void * operator new ( size_t n ) {
		char *res = allocator_memory + allocator_pos;
		allocator_pos += n;
		assert(allocator_pos <= (int)FAST_ALLOCATOR_MEMORY);
		return (void *)res;
	}
	inline void operator delete ( void * ) noexcept { }
	//inline void * operator new [] ( size_t ) { assert(0); }
	//inline void operator delete [] ( void * ) { assert(0); }
#endif

/** Fast input-output */

/** Read */

static const int buf_size = 4096;

static unsigned char buf[buf_size];
static int buf_len = 0, buf_pos = 0;

inline bool isEof() {
	if (buf_pos == buf_len) {
		buf_pos = 0, buf_len = fread(buf, 1, buf_size, stdin);
		if (buf_pos == buf_len)
			return 1;
	}
	return 0;
}

inline int getChar() { 
	return isEof() ? -1 : buf[buf_pos++];
}

inline int peekChar() { 
	return isEof() ? -1 : buf[buf_pos];
}

inline bool seekEof() { 
	int c;
	while ((c = peekChar()) != -1 && c <= 32)
		buf_pos++;
	return c == -1;
}

inline void skipBlanks() {
	while (!isEof() && buf[buf_pos] <= 32U)
		buf_pos++;
}

inline int readChar() {
	int c = getChar();
	while (c != -1 && c <= 32)
		c = getChar();
	return c;
}

inline unsigned int readUInt() {
	int c = readChar();
	unsigned int x = 0;
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return x;
}

template <class T = int>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	else if (c == '+')
		c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}

inline long long readLong() {
	return readInt<long long>();
}

inline double readDouble() {
	int s = 1, c = readChar();
	double x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	if (c == '.') {
		c = getChar();
		double coef = 1;
		while ('0' <= c && c <= '9')
			x += (c - '0') * (coef *= 1e-1), c = getChar();
	}
	return s == 1 ? x : -x;
}

inline void readWord(char *s) { 
	int c = readChar();
	while (c > 32)
		*s++ = c, c = getChar();
	*s = 0;
}

inline void readWord(string &s) {
	s.clear();
	int c = readChar();
	while (c > 32)
		s += c, c = getChar();
}

inline bool readLine(char *s) { 
	int c = getChar();
	while (c != '\n' && c != -1)
		*s++ = c, c = getChar();
	*s = 0;
	return c != -1;
}

inline bool readLine(string &s) {
	s.clear();
	int c = getChar();
	while (c != '\n' && c != -1)
		s += c, c = getChar();
	return c != -1;
}

/** Write */

static int write_buf_pos = 0;
static char write_buf[buf_size];

inline void writeChar(int x) {
	if (write_buf_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_buf_pos = 0;
	write_buf[write_buf_pos++] = x;
}

inline void flush() {
	if (write_buf_pos) {
		fwrite(write_buf, 1, write_buf_pos, stdout), write_buf_pos = 0;
		fflush(stdout);
	}
}

template <class T> 
inline void writeInt(T x, char end = 0, int output_len = -1) {
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n < output_len)
		s[n++] = '0';
	while (n--)
		writeChar(s[n]);
	if (end)
		writeChar(end);
}

inline void writeWord(const char *s) {
	while (*s)
		writeChar(*s++);
}

inline void writeWord(const string& s) {
	writeWord(s.c_str());
}

inline void writeDouble(double x, int output_len = 11) {
	if (x < 0)
		writeChar('-'), x = -x;
	int t = (int)x;
	writeInt(t), x -= t;
	writeChar('.');
	for (int i = output_len - 1; i > 0; i--) {
		x *= 10;
		t = std::min(9, (int)x);
		writeChar('0' + t), x -= t;
	}
	x *= 10;
	t = std::min(9, (int)(x + 0.5));
	writeChar('0' + t);
}

/** Buffer flusher */

static struct buffer_flusher_t {
	~buffer_flusher_t() {
		flush();
	}
} buffer_flusher;

/** Reader and writer */

struct fast_reader {
    fast_reader& operator>>(int& n) {
        n = readInt(); return *this;
    }
    fast_reader& operator>>(unsigned int& n) {
        n = readUInt(); return *this;
    }
    fast_reader& operator>>(llong& n) {
        n = readLong(); return *this;
    }
	fast_reader& operator>>(double& n) {
        n = readDouble(); return *this;
    }
	fast_reader& operator>>(float& n) {
        n = (float) readDouble(); return *this;
    }
    fast_reader& operator>>(string& s) {
        readWord(s); return *this;
    }
    fast_reader& operator>>(char& c) {
        c = (char) readChar(); return *this;
    }
    template<typename T>
    fast_reader& operator>>(vector<T>& a) {
        for (T& i : a) {
            (*this) >> i;
        }
        return *this;
    }
} f_reader;

struct fast_writer {
    template<typename T>
    fast_writer& operator<<(T n) {
        writeInt(n); return *this;
    }
	fast_writer& operator<<(double n) {
		writeDouble(n); return *this;
	}
	fast_writer& operator<<(float n) {
		writeDouble(n); return *this;
	}
    fast_writer& operator<<(const string& s) {
        writeWord(s); return *this;
    }
    fast_writer& operator<<(const char* s) {
        writeWord(s); return *this;
    }
    fast_writer& operator<<(char c) {
        writeChar(c); return *this;
    }
    template<typename T>
    fast_writer& operator<<(const vector<T>& a) {
        for (size_t i = 0; i < a.size(); ++i) {
            if (i) {
                (*this) << ' ';
            }
            (*this) << a[i];
        }
        return *this;
    }
    void flush() {
        ::flush();
    }
} f_writer;

#define cin f_reader
#define cout f_writer

#pragma GCC diagnostic pop
#endif //_LIB_FASTIO_

void solve();

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) assert(freopen(argv[1], "r", stdin));
    rng.seed(0);
#endif
#ifndef cin
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif

    int t = 1;
    for (int it = 0; it < t; it++) {
        solve();
    }

    return 0;
}

const llong M = llong(1e9) + 7;
 
struct Node {
    int l = 0;
    int r = 0;
    int h = 0;
    int h2 = 0;
};
 
vector<Node> ns;
vector<llong> ps;
vector<llong> ps2;
 
int copy(int i) {
    ns.push_back(ns[i]);
    return isz(ns) - 1;
}
 
int make() {
    ns.emplace_back();
    return isz(ns) - 1;
}
 
int upd(int i, int l, int r, int qi, int qx) {
    i = copy(i);
    if (l + 1 == r) {
        ns[i].h = qx;
        ns[i].h2 = qx;
        return i;
    }
    if (!ns[i].l) {
        ns[i].l = make();
    }
    if (!ns[i].r) {
        ns[i].r = make();
    }
    int m = (l + r) >> 1;
    if (qi < m) {
        ns[i].l = upd(ns[i].l, l, m, qi, qx);
    } else {
        ns[i].r = upd(ns[i].r, m, r, qi, qx);
    }
    
    llong lh = ns[ns[i].l].h;    
    llong rh = ns[ns[i].r].h;
    ns[i].h = lh * ps[r - m] + rh;

    llong lh2 = ns[ns[i].l].h2;    
    llong rh2 = ns[ns[i].r].h2;
    ns[i].h2 = (lh2 * ps[r - m] + rh2) % M;
    return i;
}
 
int gmin(int i, int j, int l, int r) {
    if (ns[i].h == ns[j].h && ns[i].h2 == ns[j].h2) {
        return i;
    }
    int oi = i;
    int oj = j;
    while (l + 1 < r) {
        int m = (l + r) >> 1;
        if (ns[ns[i].l].h == ns[ns[j].l].h && ns[ns[i].l].h2 == ns[ns[j].l].h2) {
            i = ns[i].r;
            j = ns[j].r;
            l = m;
        } else {
            i = ns[i].l;
            j = ns[j].l;
            r = m;
        }
    }
    if (ns[i].h <= ns[j].h) {
        return oi;
    }
    return oj;
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, string>>> g(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        string id = to_string(i + 1);
        g[x].emplace_back(y, id);
        g[y].emplace_back(x, id);
    }
 
    vector<int> d(n, 1e9);
    d[0] = 0;
    priority_queue<pair<int, int>> q;
    q.push({0, 0});
    while (isz(q)) {
        auto [dv, v] = q.top();
        q.pop();
        if (d[v] != -dv) {
            continue;
        }
        for (auto& p : g[v]) {
            int to = p.first;
            int w = isz(p.second);
            if (d[to] > d[v] + w) {
                d[to] = d[v] + w;
                q.push({-d[to], to});
            }
        }
    }
 
    int N = *max_element(begin(d), end(d));
 
    vector<int> topsort;
    vector<int> used(n);
 
    vector<vector<pair<int, string>>> rg(n);
 
    function<void(int)> dfs = [&](int v) {
        used[v] = 1;
        for (auto& p : g[v]) {
            int to = p.first;
            int w = isz(p.second);
            if (d[v] + w == d[to]) {
                rg[to].emplace_back(v, p.second);
                if (!used[to]) {
                    dfs(to);
                }
            }
        }
        topsort.push_back(v);
    };
 
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }
    
    reverse(begin(topsort), end(topsort));
 
    ps.push_back(1);
    ps2.push_back(1);
    for (int i = 0; i < N; i++) {
        ps.push_back(ps.back() * 31);
        ps2.push_back(ps2.back() * 239 % M);
    }
 
    ns.reserve(1e7);
    ns.emplace_back();
    ns.emplace_back();
    int root = 1;
    for (int i = 0; i < N; i++) {
        root = upd(root, 0, N, i, 0);
    }
 
    vector<int> rs(n);
    rs[0] = root;
 
    vector<llong> p10(N + 1);
    p10[0] = 1;
    for (int i = 1; i <= N; i++) {
        p10[i] = p10[i - 1] * 10 % M;
    }
 
    vector<llong> ans(n);
 
    for (int it = 1; it < n; it++) {
        int v = topsort[it];
        pair<int, string> pp;
        int mn = -1;
        for (auto& p : rg[v]) {
            int cur = rs[p.first];
            for (int i = 0; i < isz(p.second); i++) {
                cur = upd(cur, 0, N, d[p.first] + i, p.second[i] - '0');
            }
            if (mn == -1) {
                mn = cur;
                pp = p;
            } else {
                int z = gmin(cur, mn, 0, N);
                if (z == cur) {
                    mn = cur;
                    pp = p;
                }
            }
        }
        rs[v] = mn;
 
        ans[v] = ans[pp.first];
        for (char c : pp.second) {
            ans[v] = (ans[v] * 10 + c - '0') % M;
        }
    }
 
    for (int i = 1; i < n; i++) {
        cout << ans[i] << "\n";
    }
}