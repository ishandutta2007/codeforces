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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#ifdef ONLINE_JUDGE
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
const int N = 300015;
int n, m, fa[N], siz[N];
ll dep[N], pre[N], suf[N];
bool vis[N];
vector<pii> e[N];
map<pii, int> W;
void dfs(int u, int pa) {
	fa[u] = pa;
	for(auto [v, w] : e[u]) if(v != pa) {
		dfs(v, u);
	}
}
void dfs1(int u, int pa) {
	siz[u] = 1;
	for(auto [v, w] : e[u]) if(!vis[v] && v != pa) {
		dfs1(v, u);
		siz[u] += siz[v];
		dep[u] = max(dep[u], dep[v] + w);
	}
}
VI vec;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	// scanf("%d%d", &n, &m);
	cin >> n >> m;
	rep(i, 2, n) {
		int u, v, w;
		// scanf("%d%d%d", &u, &v, &w);
		cin >> u >> v >> w;
		e[u].emplace_back(v, w);
		e[v].emplace_back(u, w);
		W[mp(u, v)] = W[mp(v, u)] = w;
	}
	dfs(1, 0);
	int x = n;
	while(x) {
		vec.pb(x);
		vis[x] = 1;
		x = fa[x];
	}
	rep(i, 1, n) if(vis[i]) {
		dfs1(i, 0);
	}
	bool flag = 0;
	rep(i, 1, n) if(vis[i] && siz[i] > 2) {
		flag = 1;
	}
	rep(i, 1, SZ(vec) - 1) pre[i] = pre[i - 1] + W[mp(vec[i - 1], vec[i])];
	per(i, 0, SZ(vec) - 2) suf[i] = suf[i + 1] + W[mp(vec[i + 1], vec[i])];
	ll Max = -infll, res = 0;
	rep(i, 0, SZ(vec) - 1) {
		res = max(res, Max + dep[vec[i]] + suf[i]);
		if(i) {
			if(siz[vec[i]] > 1 || siz[vec[i - 1]] > 1) res = max(res, dep[vec[i - 1]] + pre[i - 1] + dep[vec[i]] + suf[i]);
			Max = max(Max, dep[vec[i - 1]] + pre[i - 1]);
		}
	}
	while(m--) {
		int lzjakioi;
		// scanf("%d", &lzjakioi);
		cin >> lzjakioi;
		if(flag) cout << pre[SZ(vec) - 1] << '\n';
		else cout << min(pre[SZ(vec) - 1], res + lzjakioi) << '\n';
	}
	return 0;
}