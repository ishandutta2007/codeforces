///
///    "Excuse me... What did you say about my hair?!"
///
///                                    -Josuke Higashikata

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) exit((cout << (x) << '\n', 0))
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;

template<class T>
class mydeque
{
private:
    T* v;
    size_t l = 0, r = 0;
    size_t cap;

    void realloc(size_t ncap)
    {
        T* nv = new T[ncap];
        if(l <= r)
            std::copy(v+l, v+r, nv);
        else
            std::copy(v+l, v+cap, nv),
            std::copy(v, v+r, nv+cap-l);
        delete[] v;
        r = l<=r? r-l: r+cap-l;
        l = 0;
        v = nv;
        cap = ncap;
    }

public:
    T& at(size_t p){return l+p<cap? v[l+p]: v[l+p-cap];}
    T& operator[](size_t p){return l+p<cap? v[l+p]: v[l+p-cap];}
    size_t size(){return l<=r? r-l: r+cap-l;}
    bool empty(){return !size();}
    void clear(){l=r=0;}
    void swap(mydeque& d){std::swap(v, d.v); std::swap(l, d.l); std::swap(r, d.r); std::swap(cap, d.cap);}
    mydeque& operator=(const mydeque& d){delete[] v; cap = d.cap; l = d.l; r = d.r; v = new T[cap]; std::copy(d.v, d.v+cap, v); return *this;}
    void pop_back(){if(--r == 0) r = cap;}
    void pop_front(){if(++l == cap) l = 0;}
    void push_back(const T& x){if(size() == cap-1) realloc(cap<<1); if(r==cap) r -= cap; v[r++] = x;}
    void push_front(const T& x){if(size() == cap-1) realloc(cap<<1); if(l==0) l += cap; v[--l] = x;}
    template<class... Args> T& emplace_back(Args&&... args){if(size() == cap-1) realloc(cap<<1); if(r==cap) r -= cap; return v[r++] = T(args...);}
    template<class... Args> T& emplace_front(Args&&... args){if(size() == cap-1) realloc(cap<<1); if(l==0) l += cap; return v[--l] = T(args...);}
    class iterator
    {
    private:
        size_t p; mydeque* d;
    public:
        iterator(size_t x, mydeque* myd) : p(x), d(myd){}
        T& operator*(){return d->at(p);}
        T* operator->(){return d->at(p);}
        iterator& operator++(){++p; return *this;}
        iterator& operator--(){--p; return *this;}
        iterator& operator+=(ptrdiff_t x){p+=x; return *this;}
        iterator& operator-=(ptrdiff_t x){p-=x; return *this;}
        iterator operator+(ptrdiff_t x){return iterator(p+x, d);}
        iterator operator-(ptrdiff_t x){return iterator(p-x, d);}
        ptrdiff_t operator-(iterator x){return p-x.p;}
        bool operator< (iterator x){return p <  x.p;}
        bool operator> (iterator x){return p >  x.p;}
        bool operator<=(iterator x){return p <= x.p;}
        bool operator>=(iterator x){return p >= x.p;}
        bool operator==(iterator x){return p == x.p;}
        bool operator!=(iterator x){return p != x.p;}

        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;
        typedef std::random_access_iterator_tag iterator_category;
    };
    iterator begin(){return iterator(size_t(0), this);}
    iterator end(){return iterator(size(), this);}
    T& front(){return *begin();}
    T& back(){return *(end()-1);}
    mydeque() : v(new T[1]), cap(1) {}
    mydeque(size_t n) : v(new T[n+1]{}), r(n), cap(n+1) {}
    mydeque(size_t n, const T& x) : v(new T[n+1]), r(n), cap(n+1) {fill(v, v+n, x);}
    mydeque(const mydeque& d) : v(new T[d.cap]), l(d.l), r(d.r), cap(d.cap){std::copy(d.v, d.v+cap, v);}
    ~mydeque(){delete[] v;}
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    mydeque<mydeque<int>> ps(26, mydeque<int> (n, 0));
    ps[s[0] - 'a'][0] = 1;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < 26; j++) {
        ps[j][i] = ps[j][i - 1] + (s[i] == j + 'a');
      }
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      long long ans = 0;
      for (int i = 0; i < 26; i++) {
        ans += 1LL * (i + 1) * (ps[i][r] - (l == 0? 0: ps[i][l - 1]));
      }
      cout << ans << '\n';
    }
  //dout("");
  return 0;
}