#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>


#include <cassert>
#include <numeric>
#include <type_traits>

namespace atcoder {

namespace internal {

#ifndef _MSC_VER
template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;

#else

template <class T> using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;

#endif

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  // namespace internal

}  // namespace atcoder

#include <cassert>
#include <vector>

namespace atcoder {

// Reference: https://en.wikipedia.org/wiki/Fenwick_tree
template <class T> struct fenwick_tree {
    using U = internal::to_unsigned_t<T>;

  public:
    fenwick_tree() : _n(0) {}
    fenwick_tree(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] += U(x);
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

  private:
    int _n;
    std::vector<U> data;

    U sum(int r) {
        U s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

}  // namespace atcoder

using namespace std;
using namespace atcoder;

// https://ei1333.github.io/luzhiled/snippets/other/random-number-generator.html
struct RandomNumberGenerator {
  mt19937 mt;

  RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}

  int operator()(int a, int b) { // [a, b)
    uniform_int_distribution< int > dist(a, b - 1);
    return dist(mt);
  }

  int operator()(int b) { // [0, b)
    return (*this)(0, b);
  }
};


void solve(){
    int n, Q;
    cin >> n >> Q;
    set<int> se;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
        se.insert(A[i]);
    }
    vector<vector<int>> query;
    vector<string> ans;
    int ind = 0;
    for(int i = 0; i < Q; i++){
        int t;
        cin >> t;
        if(t == 1){
            int ii, x;
            cin >> ii >> x;
            ii--;
            se.insert(x);
            query.push_back({t, ii, x});
        }
        else{
            int l, r, k;
            cin >> l >> r >> k;
            if((r - l + 1) % k != 0) ans.push_back("NO");
            else{
                se.insert(k);
                query.push_back({t, l, r, k, ind});
                ans.push_back("YES");
            }
            ind++;
        }
    }
    RandomNumberGenerator rnd;
    map<int, int> mp;
    ind = 0;
    for(auto s:se) mp[s] = ind++;
    for(auto &a: A) a = mp[a];
    for(auto &tmp: query){
        if(tmp[0] == 1) tmp[2] = mp[tmp[2]];
    }
    int m = se.size();
    int itr = 30;
    while(itr--){
        vector<int> P(m);
        fenwick_tree<int> bit(n);
        vector<int> B;
        copy(A.begin(), A.end(), back_inserter(B));        
        for(int i = 0; i < m; i++){
            P[i] = rnd(2);
        }        
        for(int i = 0; i < n; i++){
            if(P[B[i]]) bit.add(i, 1);
        }
        for(auto &q:query){            
            if(q[0] == 1){
                int i = q[1];
                int x = q[2];
                int b = B[i];
                B[i] = x;
                if(P[x] != P[b]){
                    if(P[x] == 1) bit.add(i, 1);
                    else bit.add(i, -1);
                }
            }
            else{
                int l = q[1];
                int r = q[2];
                int k = q[3];
                int i = q[4];
                if(ans[i] == "NO") continue;
                int tot = bit.sum(l - 1, r);
                if(tot % k != 0) ans[i] = "NO";
            }
        }
        
    }
    for(auto S:ans) cout << S << "\n";
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    // cin >> t;
    while(t--) solve();
}