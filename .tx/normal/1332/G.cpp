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
#ifndef _LIB_UTILS_
#define _LIB_UTILS_

template <typename T, T val = T()>
auto make_vector(size_t d) {
    return vector<T>(d, val);
}

template <typename T, T val = T(), typename ...Ds>
auto make_vector(size_t d, Ds... ds) {
    return vector<decltype(make_vector<T, val>(ds...))>(d, make_vector<T, val>(ds...));
}
#endif //_LIB_UTILS_

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
    // cin >> t;
    for (int it = 0; it < t; it++) {
        solve();
    }

    return 0;
}

void solve() {
    struct ST {
        vector<int> mx;
        vector<int> add;
        ST(int n) {
            mx.assign(4 * n, 0);
            add.assign(4 * n, 0);
        }

        void push(int i, int l, int r) {
            mx[i] += add[i];
            if (l + 1 < r) {
                add[i + i + 1] += add[i];
                add[i + i + 2] += add[i];
            }
            add[i] = 0;
        }

        void upd(int i, int l, int r, int ql, int qr, int qx) {
            push(i, l, r);
            if (r <= ql || qr <= l) {
                return;
            }
            if (ql <= l && r <= qr) {
                add[i] += qx;
                push(i, l, r);
                return;
            }
            int m = (l + r) >> 1;
            upd(i * 2 + 1, l, m, ql, qr, qx);
            upd(i * 2 + 2, m, r, ql, qr, qx);
            mx[i] = max(mx[i * 2 + 1], mx[i * 2 + 2]);
        }

        int left2(int i, int l, int r) {
            push(i, l, r);
            if (mx[i] != 2) {
                return -1;
            }
            if (l + 1 == r) {
                return l;
            }
            int m = (l + r) >> 1;
            int res = left2(i * 2 + 1, l, m);
            if (res == -1) {
                res = left2(i * 2 + 2, m, r);
            }
            return res;
        }
    };

    struct STM {
        vector<pair<int, int>> mx;
        int inf;
        STM(int n, vector<int>& a, int inf) {
            mx.resize(4 * n);
            build(0, 0, n, a);
            this->inf = inf;
        }
        
        void build(int i, int l, int r, vector<int>& a) {
            if (l + 1 == r) {
                mx[i] = {a[l], l};
            } else {
                int m = (l + r) >> 1;
                build(i * 2 + 1, l, m, a);
                build(i * 2 + 2, m, r, a);
                mx[i] = max(mx[i * 2 + 1], mx[i * 2 + 2]);
            }
        }

        pair<int, int> mxpos(int i, int l, int r, int ql, int qr) {
            if (r <= ql || qr <= l) {
                return {-inf, -inf};
            }
            if (ql <= l && r <= qr) {
                return mx[i];
            }
            int m = (l + r) >> 1;
            return max(mxpos(i * 2 + 1, l, m, ql, qr), mxpos(i * 2 + 2, m, r, ql, qr));
        }
    };

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    cin >> a;
    vector<int> z(n, n);
    vector<int> zp(n);
    iota(begin(zp), end(zp), 0);
    stack<int> ge, le;
    ge.push(n);
    le.push(n);
    ST st(n);
    vector<vector<int>> cheatl(n), cheatg(n);
    for (int i = n - 1; i >= 0; i--) {
        while (isz(ge) > 1 && a[i] >= a[ge.top()]) {
            int t = ge.top();
            ge.pop();
            if (t + 1 != ge.top()) {
                st.upd(0, 0, n, t + 1, ge.top(), -1);
            }
            if (a[t] == a[i]) {
                swap(cheatg[i], cheatg[t]);
                cheatg[i].push_back(t);
            } else {
                for (int x : cheatg[t]) {
                    st.upd(0, 0, n, x, x + 1, 1);
                }
            }
        }
        bool fl = (isz(ge) > 1 && a[i] == a[ge.top()]); 
        while (isz(le) > 1 && a[i] <= a[le.top()]) {
            int t = le.top();
            le.pop();
            if (t + 1 != le.top()) {
                st.upd(0, 0, n, t + 1, le.top(), -1);
            }
            if (a[t] == a[i]) {
                swap(cheatl[i], cheatl[t]);
                cheatl[i].push_back(t);
            } else {
                for (int x : cheatl[t]) {
                    st.upd(0, 0, n, x, x + 1, 1);
                }
            }
        }
        // bool fl2 = (isz(le) > 1 && a[i] == a[le.top()]);
        int x = st.left2(0, 0, n);
        if (x != -1) {
            z[i] = x;
        }
        if (i + 1 < n) {
            if (z[i + 1] < z[i]) {
                z[i] = z[i + 1];
                zp[i] = zp[i + 1];
            }
        }
        if (i + 1 != ge.top()) {
            st.upd(0, 0, n, i + 1, ge.top(), 1);
            if (isz(cheatg[i])) {
                int x = cheatg[i].back();
                st.upd(0, 0, n, x, x + 1, -1);
            }
        }
        ge.push(i);
        if (i + 1 != le.top()) {
            st.upd(0, 0, n, i + 1, le.top(), 1);
            if (isz(cheatl[i])) {
                int x = cheatl[i].back();
                st.upd(0, 0, n, x, x + 1, -1);
            }
        }
        le.push(i);
    }

    vector<int> lg(n, -1), ll(n, -1), rg(n, -1), rl(n, -1);
    stack<int> sl, sg;
    for (int i = 0; i < n; i++) {
        while (isz(sg) && a[i] >= a[sg.top()]) {
            sg.pop();
        }
        if (isz(sg)) {
            lg[i] = sg.top();
        }
        sg.push(i);
        while (isz(sl) && a[i] <= a[sl.top()]) {
            sl.pop();
        }
        if (isz(sl)) {
            ll[i] = sl.top();
        }
        sl.push(i);;
    }
 
    sl = stack<int>();
    sg = stack<int>();
    for (int i = n - 1; i >= 0; i--) {
        while (isz(sg) && a[i] >= a[sg.top()]) {
            sg.pop();
        }
        if (isz(sg)) {
            rg[i] = sg.top();
        }
        sg.push(i);
        while (isz(sl) && a[i] <= a[sl.top()]) {
            sl.pop();
        }
        if (isz(sl)) {
            rl[i] = sl.top();
        }
        sl.push(i);
    }

    vector<int> kek2(n, n), snd(n, n), from(n, n);
    for (int i = n - 2; i >= 0; i--) {
        kek2[i] = kek2[i + 1];
        snd[i] = snd[i + 1];
        from[i] = from[i + 1];
        {
            int t = rg[i];
            if (t != -1) {
                int z = rl[t];
                if (z != -1 && z < kek2[i]) {
                    kek2[i] = z;
                    from[i] = i;
                    snd[i] = t;
                }
            }
        }
        {
            int t = rl[i];
            if (t != -1) {
                int z = rg[t];
                if (z != -1 && z < kek2[i]) {
                    kek2[i] = z;
                    from[i] = i;
                    snd[i] = t;
                }
            }
        }
        if (kek2[i] != n) {
            int x = from[i];
            int y = snd[i];
            int z = kek2[i];
            assert(x < y && y < z);
            assert(a[x] != a[y] && a[y] != a[z] && ((a[x] < a[y]) != (a[y] < a[z])));
        }
    }
 
    vector<int> kekl(n), kekr(n);
    for (int i = 0; i < n; i++) {
        if (rg[i] == -1 || rl[i] == -1) {
            kekr[i] = n;
        } else {
            kekr[i] = max(rg[i], rl[i]);
        }
        if (lg[i] == -1 || ll[i] == -1) {
            kekl[i] = -1;
        } else {
            kekl[i] = min(lg[i], ll[i]);
        }
    }
 
    vector<int> closel(n), closer(n);
    closer[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        if (kekr[i] > kekr[closer[i + 1]]) {
            closer[i] = closer[i + 1];
        } else {
            closer[i] = i;
        }
    }
    for (int i = 1; i < n; i++) {
        if (kekl[i] < kekl[closel[i - 1]]) {
            closel[i] = closel[i - 1];
        } else {
            closel[i] = i;
        }
    }

    STM stmx(n, a, 1e9);
    for (int& i : a) {
        i = -i;
    }
    STM stmn(n, a, 1e9);

    // cout << zp << "\n" << z << "\n";
    // return;
#define fuck if (n == 199985 && q == 200000 && iq == 51579) { assert(false); }
    for (int iq = 0; iq < q; iq++) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        if (z[l] <= r) {
            int a = zp[l];
            int b = z[l];
            int mx = stmx.mxpos(0, 0, n, a + 1, b).second;
            int mn = stmn.mxpos(0, 0, n, a + 1, b).second;

            cout << "4\n" << a + 1 << " " << min(mn, mx) + 1 << " " << max(mn, mx) + 1 << " " << b + 1 << "\n";
            continue;
        }

        if (kek2[l] <= r) {
            cout << "3\n";
            cout << from[l] + 1 << " " << snd[l] + 1 << " " << kek2[l] + 1 << "\n";
            if (a[from[l]] == a[snd[l]] || a[from[l]] == a[kek2[l]] || a[snd[l]] == a[kek2[l]]) {
                // assert(false);
            }
            // fuck;
            continue;
        }

        // if (kekr[closer[l]] <= r) {
        //     l = closer[l];
        //     int x = rg[l];
        //     int y = rl[l];
        //     cout << "3\n";
        //     cout << l + 1 << " " << min(x, y) + 1 << " " << max(x, y) + 1 << "\n";
        //     continue;
        // }
        // if (kekl[closel[r]] >= l) {
        //     r = closel[r];
        //     int x = lg[r];
        //     int y = ll[r];
        //     cout << "3\n";
        //     cout << min(x, y) + 1 << " " << max(x, y) + 1 << " " << r + 1 << "\n";
        //     continue;
        // }
        cout << "0\n\n";
    }
}