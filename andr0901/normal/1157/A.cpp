#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define in :

template<typename T>
struct number_iterator : std::iterator<random_access_iterator_tag, T>{
    T a;
    number_iterator(T _a) : a(_a) {}
    operator T&(){return a;}
    T operator *() const {return a;}
};

template <typename T>
struct number_range {
    T s, f;
    number_range(T s, T f):s(s),f(f){}
    number_iterator<T> begin(){return s;}
    number_iterator<T> end(){return f;}
};

template<typename T> number_range<T> range(T f) {return number_range<T>(0, f);}

template<typename T> number_range<T> range(T s, T f) {return number_range<T>(s, f);}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    map <int, int> used;
    while (n) {
        if (used[n])
            break;
        used[n] = 1;
        n++;
        while (n && n % 10 == 0) 
            n /= 10;
    }
    cout << sz(used);
    return 0;
}