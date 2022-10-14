#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 200100, logN = 20, M = 6e6;

int mn[N << 2], mx[N << 2], lz[N << 2];

void pull(int id) {
    mn[id] = min(mn[id << 1], mn[id << 1 | 1]);
    mx[id] = max(mx[id << 1], mx[id << 1 | 1]);
}

void give(int id, int v) {
    mn[id] += v, mx[id] += v, lz[id] += v;
}

void push(int id) {
    if (!lz[id])
        return;
    give(id << 1, lz[id]), give(id << 1 | 1, lz[id]), lz[id] = 0;
}

void add(int a, int b, int v, int l = 0, int r = N, int id = 1) {
    if (a <= l && r <= b)
        give(id, v);
    else {
        push(id);
        if (a < (l + r >> 1))
            add(a, b, v, l, l + r >> 1, id << 1);
        if ((l + r >> 1) < b)
            add(a, b, v, l + r >> 1, r, id << 1 | 1);
        pull(id);
    }
}

int find_first0(int st, int l = 0, int r = N, int id = 1) {
    if (r - l == 1)
        return (mn[id] == 0 ? l : -1);
    push(id);
    if (st <= l) {
        if (!mn[id << 1])
            return find_first0(st, l, l + r >> 1, id << 1);
        if (!mn[id << 1 | 1])
            return find_first0(st, l + r >> 1, r, id << 1 | 1);
        return -1;
    }
    if (st < (l + r >> 1)) {
        int x = find_first0(st, l, l + r >> 1, id << 1);
        if (x != -1)
            return x;
    }
    return find_first0(st, l + r >> 1, r, id << 1 | 1);
}

int find_first1(int st, int l = 0, int r = N, int id = 1) {
    if (r - l == 1)
        return (mx[id] == 1 ? l : -1);
    push(id);
    if (st <= l) {
        if (mx[id << 1])
            return find_first1(st, l, l + r >> 1, id << 1);
        if (mx[id << 1 | 1])
            return find_first1(st, l + r >> 1, r, id << 1 | 1);
        return -1;
    }
    if (st < (l + r >> 1)) {
        int x = find_first1(st, l, l + r >> 1, id << 1);
        if (x != -1)
            return x;
    }
    return find_first1(st, l + r >> 1, r, id << 1 | 1);
}

int find_last1(int l = 0, int r = N, int id = 1) {
    if (r - l == 1)
        return l;
    push(id);
    if (mx[id << 1 | 1] == 1)
        return find_last1(l + r >> 1, r, id << 1 | 1);
    return find_last1(l, l + r >> 1, id << 1);
}

#include<unistd.h>
char OB[65536]; int OP;
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
inline int R(){static char c;int a;while((c=RC())<'0');a=c^'0';while((c=RC())>='0')a*=10,a+=c^'0';return a;}
inline void W(int n){static char buf[12],p;if(n==0)OB[OP++]='0';p=0;while(n)buf[p++]='0'+(n%10),n/=10;for(--p;p>=0;--p)OB[OP++]=buf[p];if(OP>65520)write(1,OB,OP),OP=0;}

int main () {
    int n = R(), q = R();
    vector <int> a(n), T(n);
    for (int i = 0; i < n; ++i) {
        a[i] = R();
        int zero = find_first0(a[i]);
        add(zero, zero + 1, 1);
        if (a[i] < zero)
            add(a[i], zero, -1);
    }
    for (int i = 1; i <= q; ++i) {
        int p = R() - 1;
        // del a[p]
        int one = find_first1(a[p]);
        add(one, one + 1, -1);
        if (a[p] < one)
            add(a[p], one, 1);
        a[p] = R();
        // add a[p]
        int zero = find_first0(a[p]);
        add(zero, zero + 1, 1);
        if (a[p] < zero)
            add(a[p], zero, -1);
        W(find_last1()), OB[OP++] = '\n';
    }
    write(1,OB,OP);
}