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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
const int N = 100015;
int n, x[N], y[N], c[N], ans;
struct fenwick {
	unsigned short d[N];
	void clear() {memset(d, 0, sizeof d);}
	void add(int p) { for(; p <= n; p += lowbit(p)) d[p]++;}
	inline unsigned short query(int p) { int res = 0; for(; p; p -= lowbit(p)) res += d[p]; return res;}
	inline unsigned short query(int l, int r) { return query(r) - query(l - 1);}
};
struct solver {
	vector<array<int, 3>> vec;
	int cnt[3];
	fenwick vx[3], vy[3];
	void clear() {
		rep(p, 0, 2) vx[p].clear(), vy[p].clear();
	}
	int calc() {
		int ans = 0;
		rep(Eric_hoo, 0, 1) {
			clear();
			sort(all(vec), [&](auto u, auto v) {
				return u[Eric_hoo] < v[Eric_hoo];
			});
			cnt[0] = cnt[1] = cnt[2] = SZ(vec) / 3;
			int ptr = 0;
			for(auto o : vec) {
				while(ptr < SZ(vec) && vec[ptr][Eric_hoo] < o[Eric_hoo]) {
					vx[vec[ptr][2]].add(vec[ptr][0]);
					vy[vec[ptr][2]].add(vec[ptr][1]);
					cnt[vec[ptr][2]]--;
					ptr++;
				}
				int p = o[2];
				int res = cnt[p], Max = 0;
				int a = (p + 1) % 3, b = (p + 2) % 3;
				rep(_, 0, 1) {
					int l = 1, r = n;
					while(l <= r) {
						int mid = (l + r) >> 1;
						int qa = vx[a].query(1, mid), qb = vx[b].query(mid + 1, n);
						Max = max(Max, min(qa, qb));
						if(qa >= qb) r = mid - 1;
						else l = mid + 1;
					}
					l = 1, r = n;
					while(l <= r) {
						int mid = (l + r) >> 1;
						int qa = vy[a].query(1, mid), qb = vy[b].query(mid + 1, n);
						Max = max(Max, min(qa, qb));
						if(qa >= qb) r = mid - 1;
						else l = mid + 1;
					}
					swap(a, b);
				}
				ans = max(ans, min(res, Max));
			}
		}
		return ans;
	}
} fuck;
void lsh(int a[]) {
	VI vec;
	rep(i, 1, n) vec.pb(a[i]);
	sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
	rep(i, 1, n) a[i] = lower_bound(all(vec), a[i]) - vec.begin() + 1;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin >> n;
	rep(i ,1, n) cin >> x[i] >> y[i] >> c[i], c[i]--;
	lsh(x); lsh(y);
	for(int p : {-1, 1}) {
		fuck.vec.clear();
		auto Fuck = [&](int x) {
			return x <= 0 ? x + n + 1 : x;
		};
		rep(i, 1, n) fuck.vec.pb({Fuck(p * x[i]), Fuck(p * y[i]), c[i]});
		ans = max(ans, fuck.calc());
	}
	cout << ans * 3;
	return 0;
}