#include <iostream>

using namespace std;



/** Interface */

inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );

/** Read */

static const int buf_size = 4096;

inline int getChar() {
	static char buf[buf_size];
	static int len = 0, pos = 0;
	if (pos == len)
		pos = 0, len = fread(buf, 1, buf_size, stdin);
	if (pos == len)
		return -1;
	return buf[pos++];
}

inline int readChar() {
	int c = getChar();
	while (c <= 32)
		c = getChar();
	return c;
}

template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
	if (write_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
	write_buf[write_pos++] = x;
}

template <class T> 
inline void writeInt( T x, char end ) {
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		writeChar(s[n]);
	if (end)
		writeChar(end);
}

inline void writeWord( const char *s ) {
	while (*s)
		writeChar(*s++);
}

struct Flusher {
	~Flusher() {
		if (write_pos)
			fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
	}
} flusher;

/** Example */

/** Begin fast allocation */
const int MAX_MEM = 1.3e8;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new ( size_t n ) {
	char *res = mem + mpos;
	mpos += n;
	return (void *)res;
}
inline void operator delete ( void * ) { } // !
//inline void * operator new [] ( size_t ) { assert(0); }
//inline void operator delete [] ( void * ) { assert(0); }
/** End fast allocation */


typedef long long ll;

const int N = 2e5 + 1;

int a[N];

ll A = 13, B = 19, X = 223, Y = 239, Z = 97, MOD = 1e9 + 993;
 
ll myrand()
{
    ll C = (A * X + B * Y + Z) % MOD;
    A = B;
    B = C;
    return A;
}

struct treap
{
    treap *l, *r;
    int x, y;
    int sz, cnt;
    treap(int x): x(x), y(myrand()), sz(1), cnt(1), l(0), r(0) {}
    treap() {}
};

inline void recalc(treap *t)
{
    if (!t)
    {
        return;
    }
    t->sz = t->cnt;
    if (t->l)
    {
        t->sz += t->l->sz;
    }
    if (t->r)
    {
        t->sz += t->r->sz;
    }
}

inline pair <treap *, treap *> split(treap *t, int x)
{
    if (!t)
    {
        return {0, 0};
    }
    if (x < t->x)
    {
        recalc(t);
        auto a = split(t->l, x);
        t->l = a.second;
        recalc(t);
        recalc(a.first);
        return {a.first, t};
    }
    else
    {
        recalc(t);
        auto a = split(t->r, x);
        t->r = a.first;
        recalc(t);
        recalc(a.second);
        return {t, a.second};
    }
}

inline treap *merge(treap *l, treap *r)
{
    if (!l)
    {
        return r;
    }
    if (!r)
    {
        return l;
    }
    if (l->y > r->y)
    {
        recalc(l);
        recalc(r);
        l->r = merge(l->r, r);
        recalc(l);
        return l;
    }
    else
    {
        recalc(l);
        recalc(r);
        r->l = merge(l, r->l);
        recalc(r);
        return r;
    }
}

inline int get_val(treap *t)
{
    if (!t)
    {
        return 0;
    }
    recalc(t);
    return t->sz;
}

inline treap* del(treap *&t, int x)
{
    if (t->x == x)
    {
        if (t->cnt == 1)
        {
            t = merge(t->l, t->r);
        }
        else
        {
            t->cnt--;
            recalc(t);
        }
        return t;
    }
    else if (x < t->x)
    {
        t->l = del(t->l, x);
        recalc(t);
        return t;
    }
    else
    {
        t->r = del(t->r, x);
        recalc(t);
        return t;
    }
}

inline void insert(treap *&t, treap *x)
{
    if (!t)
    {
        t = x;
        return;
    }
    if (x->y > t->y)
    {
        auto a = split(t, x->x);
        x->l = a.first;
        x->r = a.second;
        t = x;
        recalc(t);
    }
    else
    {
        if (x->x < t->x)
        {
            insert(t->l, x);
        }
        else
        {
            insert(t->r, x);
        }
        recalc(t);
    }
}

bool check(treap *t, int x)
{
    if (!t)
    {
        return 0;
    }
    if (t->x == x)
    {
        t->cnt++;
        recalc(t);
        return true;
    }
    else if (x < t->x)
    {
        bool lel = check(t->l, x);
        recalc(t);
        return lel;
    }
    else
    {
        bool lel = check(t->r, x);
        recalc(t);
        return lel;
    }
}

inline void add(treap *&t, int x)
{
    if (check(t, x))
    {
        return;
    }
    insert(t, new treap(x));
}

inline int get(treap *&t, int l, int r)
{
    auto a = split(t, r);
    auto b = split(a.first, l - 1);
    int kek = get_val(b.second);
    a.first = merge(b.first, b.second);
    t = merge(a.first, a.second);
    return kek;
}

treap *fenw[N];

inline void upd(int x, int y)
{
    for (; x < N; x = (x | (x + 1)))
    {
        add(fenw[x], y);
    }
}

inline void nopd(int x, int y)
{
    for (; x < N; x = (x | (x + 1)))
    {
        fenw[x] = del(fenw[x], y);
    }
}

inline int get(int x, int l, int r)
{
    int res = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1)
    {
        res += get(fenw[x], l, r);
    }
    return res;
}

inline int get(int x1, int x2, int y1, int y2)
{
    x2--, y2--;
    return get(x2, y1, y2) - get(x1 - 1, y1, y2);
}

int main()
{
    srand('M' + 'R' + '.' + 'D' + 'U' + 'D' + 'E' + 'C');
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    int n = readInt(), q = readInt();
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
        upd(i, a[i]);
    }
    ll res = 0;
    for (int i = 0; i < q; i++)
    {
        int l = readInt(), r = readInt();
        l--, r--;
        if (l > r)
        {
            swap(l, r);
        }
        if (l != r)
        {
            res -= get(l, r + 1, 0, a[l]);
            res -= get(l, r + 1, a[r] + 1, n);
            res += (a[min(l, r)] > a[max(l, r)]);
            nopd(l, a[l]);
            nopd(r, a[r]);
            swap(a[l], a[r]);
            upd(l, a[l]);
            upd(r, a[r]);
            res += get(l, r + 1, a[r] + 1, n);
            res += get(l, r + 1, 0, a[l]);
            res -= (a[min(l, r)] > a[max(l, r)]);
        }
        writeInt(res, '\n');
    }
}