#pragma GCC optimize("O1")
#include <bits/stdc++.h>
 
using namespace std;
 
//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
 
#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif
 
template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}
 
int n;
 
class Segtree {
  private:
    long long sum = 0;
    int rev = 0;
    int swp = 0;
    Segtree *l = 0, *r = 0;
 
    void push() {
        if (rev & 1) {
            std::swap(l, r);
            rev ^= (1 << 1);
        }
        if (swp & 1)
            std::swap(l, r);
 
        if (l) {
            l -> rev ^= (rev >> 1);
            l -> swp ^= (swp >> 1);
        }
        if (r) {
            r -> rev ^= (rev >> 1);
            r -> swp ^= (swp >> 1);
        }
 
        rev = swp = 0;
    }
 
    long long get(int vl, int vr, int ql, int qr) {
        push();
        if (vr <= ql || qr <= vl)
            return 0;
        if (ql <= vl && vr <= qr)
            return sum;
        int vm = vl + vr >> 1;
        long long ans = 0;
        if (l)
            ans += l -> get(vl, vm, ql, qr);
        if (r)
            ans += r -> get(vm, vr, ql, qr);
        return ans;
    }
 
    void upd(int vl, int vr, int idx, int val) {
        push();
        if (vr - vl == 1) {
            sum = val;
            return;
        }
        int vm = vl + vr >> 1;
        if (idx < vm)
            l -> upd(vl, vm, idx, val);
        else
            r -> upd(vm, vr, idx, val);
        sum = l -> sum + r -> sum; 
    }
 
  public:
    Segtree(int vl, int vr) {
        if (vr - vl == 1)
            return;
        int vm = vl + vr >> 1;
        l = new Segtree(vl, vm);
        r = new Segtree(vm, vr);
    }
 
    long long get(int l, int r) {
        return get(0, 1 << n, l, r);
    }
 
    void upd(int idx, int val) {
        upd(0, 1 << n, idx, val);
    }
 
 
    void reverse(int lvl) {
        rev ^= (1 << (n - lvl));
    }
 
    void swap(int lvl) {
        swp ^= (1 << (n - lvl - 1));
    }
};
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> n >> q;
    Segtree tr(0, 1 << n);
    forn (i, 0, 1 << n) {
        int x;
        cin >> x;
        tr.upd(i, x);
    }
    cerr << tr.get(0, 1 << n) << "\n";
    while (q --> 0) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int x, k;
            cin >> x >> k, --x;
            tr.upd(x, k);
        }
        if (tp == 2) {
            int k;
            cin >> k;
            tr.reverse(k);
        }
        if (tp == 3) {
            int k;
            cin >> k;
            tr.swap(k);
        }
        if (tp == 4) {
            int l, r;
            cin >> l >> r, --l;
            cout << tr.get(l, r) << "\n";
        }
       /* forn (i, 0, 1 << n)
            cerr << tr.get(i, i + 1) << " ";*/
        cerr << "\n";
    }
    return 0;
}