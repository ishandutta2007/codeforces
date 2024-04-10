#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

typedef class Input {
	protected:
		const static int limit = 65536;
		FILE* file; 

		int ss, st;
		char buf[limit];
	public:
		
		Input() : file(NULL)	{	};
		Input(FILE* file) : file(file) {	}

		void open(FILE *file) {
			this->file = file;
		}

		void open(const char* filename) {
			file = fopen(filename, "r");
		}

		char pick() {
			if (ss == st)
				st = fread(buf, 1, limit, file), ss = 0;//, cerr << "str: " << buf << "ed " << st << endl;
			return buf[ss++];
		}
} Input;

#define digit(_x) ((_x) >= '0' && (_x) <= '9')

Input& operator >> (Input& in, unsigned& u) {
	char x;
	while (~(x = in.pick()) && !digit(x));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	return in;
}

Input& operator >> (Input& in, unsigned long long& u) {
	char x;
	while (~(x = in.pick()) && !digit(x));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	return in;
}

Input& operator >> (Input& in, int& u) {
	char x;
	while (~(x = in.pick()) && !digit(x) && x != '-');
	int aflag = ((x == '-') ? (x = in.pick(), -1) : (1));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	u *= aflag;
	return in;
}

Input& operator >> (Input& in, long long& u) {
	char x;
	while (~(x = in.pick()) && !digit(x) && x != '-');
	int aflag = ((x == '-') ? (x = in.pick(), -1) : (1));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	u *= aflag;
	return in;
}

Input& operator >> (Input& in, double& u) {
	char x;
	while (~(x = in.pick()) && !digit(x) && x != '-');
	int aflag = ((x == '-') ? (x = in.pick(), -1) : (1));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	if (x == '.') {
		double dec = 1;
		for ( ; ~(x = in.pick()) && digit(x); u = u + (dec *= 0.1) * (x - '0'));
	}
	u *= aflag;
	return in;
}

Input& operator >> (Input& in, char* str) {
	char x;
	while (~(x = in.pick()) && x != '\n' && x != ' ')
		*(str++) = x;
	*str = 0;
	return in;
}

Input in (stdin);

typedef class Output {
	protected:
		const static int Limit = 65536;
		char *tp, *ed;
		char buf[Limit];
		FILE* file;
		int precision;

		void flush() {
			fwrite(buf, 1, tp - buf, file);
			fflush(file);
			tp = buf;
		}

	public:

		Output() {	}
		Output(FILE* file) : tp(buf), ed(buf + Limit), file(file), precision(6) {	}
		Output(const char *str) : tp(buf), ed(buf + Limit), precision(6) {
			file = fopen(str, "w");
		}
		~Output() {
			flush();
		}

		void put(char x) {
			if (tp == ed)
				flush();
			*(tp++) = x;
		}

		int get_precision() {
			return precision;
		}
		void set_percision(int x) {
			precision = x;
		}
} Output;

Output& operator << (Output& out, int x) {
	static char buf[35];
	static char * const lim = buf + 34;
	if (!x)
		out.put('0');
	else {
		if (x < 0)
			out.put('-'), x = -x;
		char *tp = lim;
		for ( ; x; *(--tp) = x % 10, x /= 10);
		for ( ; tp != lim; out.put(*(tp++) + '0'));
	}
	return out;
}

Output& operator << (Output& out, long long x) {
	static char buf[36];
	static char * const lim = buf + 34;
	if (!x)
		out.put('0');
	else {
		if (x < 0)
			out.put('-'), x = -x;
		char *tp = lim;
		for ( ; x; *(--tp) = x % 10, x /= 10);
		for ( ; tp != lim; out.put(*(tp++) + '0'));
	}
	return out;
}

Output& operator << (Output& out, unsigned x) {
	static char buf[35];
	static char * const lim = buf + 34;
	if (!x)
		out.put('0');
	else {
		char *tp = lim;
		for ( ; x; *(--tp) = x % 10, x /= 10);
		for ( ; tp != lim; out.put(*(tp++) + '0'));
	}
	return out;
}

Output& operator << (Output& out, char x)  {
	out.put(x);
	return out;
}

Output& operator << (Output& out, const char* str) {
	for ( ; *str; out.put(*(str++)));
	return out;
}

Output& operator << (Output& out, double x) {
	int y = x;
	x -= y;
	out << y << '.';
	for (int i = out.get_precision(); i; i--, y = x * 10, x = x * 10 - y, out.put(y + '0'));
	return out;
}

Output out (stdout);

#define pii pair<int, int>

const int inf = (signed) (~0u >> 2);

typedef class Dsu {
	public:
		int n;
		int *f, *sz;
		stack<int> stk;

		void init(int n) {
			this->n = n;
			f = new int[(n + 1)];
			sz = new int[(n + 1)];
			for (int i = 0; i <= n; i++) {
				f[i] = i;
				sz[i] = 1;
			}
		}

		int find(int x) {
			int cnt = 0;
			while (f[x] ^ x)
				x = f[x], ++cnt;
			if (cnt > 100)
				cerr << "cnt: " << cnt << '\n';
			return x;
		}
		boolean unit(int x, int y) {
			x = find(x), y = find(y);
			if (x ^ y) {
				if (sz[x] > sz[y])
					swap(x, y);
				stk.push(x);
				f[x] = y;
				sz[y] += sz[x];
				return true;
			}
			return false;
		}

		void revoke() {
			int x = stk.top();
			int y = f[x];
			f[x] = x;
			sz[y] -= sz[x];
			stk.pop();
		}
} Dsu;

typedef class Edge {
	public:
		int u, v, w;

		Edge() : u(0), v(0), w(0) {	}

		void read() {
			in >> u >> v >> w;
		}
} Edge;

typedef class Event {
	public:
		int x, id;

		Event(int x, int id) : x(x), id(id) {	}
} Event;

int n, m, q;
Edge *E;
Dsu dsu;
boolean *ans;
vector<Event> vE;

boolean operator < (Event a, Event b) {
	if (E[a.x].w ^ E[b.x].w)
		return E[a.x].w < E[b.x].w;
	return a.id > b.id;
}

int main() {
	in >> n >> m;
	E = new Edge[(m + 1)];
	for (int i = 1; i <= m; i++) {
		E[i].read();
		vE.emplace_back(i, 0);
	}
	in >> q;
	ans = new boolean[q + 1];
	for (int i = 1; i <= q; i++)
		ans[i] = true;
	for (int i = 1, k, x; i <= q; i++) {
		in >> k;
		while (k--) {
			in >> x;
			vE.emplace_back(x, i);
		}
	}
	sort(vE.begin(), vE.end());
//	cerr << "sz: " << vE.size() << '\n';
	dsu.init(n);
	for (int i = 0, j = 0, sz = vE.size(); i < sz; i = j) {
		int id = vE[i].id;
		while (j < sz && vE[j].id == id)
			j++;
		if (id) {
			int cnt = 0, tmp;
			while (i < j) {
				tmp = 0;
				ans[id] = ans[id] && (tmp = dsu.unit(E[vE[i].x].u, E[vE[i].x].v));
				cnt += tmp;
				i++;
			}
			while (cnt--)
				dsu.revoke();
//			cerr << "miaomiao: " << id << " " << dsu.stk.size() << '\n';
		} else {
			while (i < j) {
				dsu.unit(E[vE[i].x].u, E[vE[i].x].v);
				i++;
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		out << (ans[i] ? "YES" : "NO") << '\n';
	}
	return 0;
}