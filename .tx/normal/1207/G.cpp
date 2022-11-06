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

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) assert(freopen(argv[1], "r", stdin));
    rng.seed(0);
#endif
#ifndef cin
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif

    struct Node {
        vector<int> ch = vector<int>(26, -1);
        vector<int> q_ids;
        int suf = -1;
        vector<int> back_suf;
    };

    vector<Node> na, nb;

    na.emplace_back();


    int n;
    cin >> n;
    vector<int> a_id(n);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            string s;
            cin >> s;
            int c = s[0] - 'a';
            if (na[0].ch[c] == -1) {
                na[0].ch[c] = isz(na);
                na.emplace_back();
            }
            a_id[i] = na[0].ch[c];
        } else {
            int x;
            string s;
            cin >> x >> s;
            int c = s[0] - 'a';
            x = a_id[x - 1];
            if (na[x].ch[c] == -1) {
                na[x].ch[c] = isz(na);
                na.emplace_back();
            }
            a_id[i] = na[x].ch[c];
        }
    }

    int q;
    cin >> q;

    nb.emplace_back();
    nb.emplace_back();
    vector<int> b_id(q);

    for (int iq = 0; iq < q; iq++) {
        int x;
        string s;
        cin >> x >> s;
        --x;
        na[a_id[x]].q_ids.push_back(iq);
        int cur = 1;
        for (int i = 0; i < isz(s); i++) {
            int c = s[i] - 'a';
            if (nb[cur].ch[c] == -1) {
                nb[cur].ch[c] = isz(nb);
                nb.emplace_back();
            }
            cur = nb[cur].ch[c];
        }
        b_id[iq] = cur;
    }

    vector<int> order;
    {
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            order.push_back(v);
            for (int i = 0; i < 26; i++) {
                if (nb[v].ch[i] != -1) {
                    q.push(nb[v].ch[i]);
                }
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        nb[0].ch[i] = 1;
    }

    nb[1].suf = 0;
    nb[0].back_suf.push_back(1);

    for (int v : order) {
        for (int i = 0; i < 26; i++) {
            int to = nb[nb[v].suf].ch[i];
            if (nb[v].ch[i] == -1) {
                nb[v].ch[i] = to;
            } else {
                nb[nb[v].ch[i]].suf = to;
                nb[to].back_suf.push_back(nb[v].ch[i]);
            }
        }
    }

    vector<int> tin(isz(nb));
    vector<int> sz(isz(nb));
    int timer = 0;

    function<void(int)> dfs_b = [&](int v) {
        tin[v] = timer++;
        sz[v] = 1;
        for (int i : nb[v].back_suf) {
            dfs_b(i);
            sz[v] += sz[i];
        }
    };

    dfs_b(0);

    struct fenw {
        vector<int> a;

        fenw(int n) {
            a.resize(n);
        }

        void add(int i, int x) {
            for (; i < isz(a); i |= i + 1) {
                a[i] += x;
            }
        }

        int get(int r) {
            int res = 0;
            for (; r >= 0; r = (r & (r + 1)) - 1) {
                res += a[r];
            }
            return res;
        }

        int get(int l, int r) {
            int res = get(r);
            if (l) {
                res -= get(l - 1);
            }
            return res;
        }
    };

    fenw fw(timer);

    vector<int> ans(q);

    function<void(int, int)> dfs_a = [&](int v, int b) {
        fw.add(tin[b], 1);
        for (int q_id : na[v].q_ids) {
            ans[q_id] = fw.get(tin[b_id[q_id]], tin[b_id[q_id]] + sz[b_id[q_id]] - 1);
        }

        for (int i = 0; i < 26; i++) {
            int to = na[v].ch[i];
            if (to == -1) {
                continue;
            }
            dfs_a(to, nb[b].ch[i]);
        }

        fw.add(tin[b], -1);
    };

    dfs_a(0, 1);

    for (int i : ans) {
        cout << i << "\n";
    }

    return 0;
}