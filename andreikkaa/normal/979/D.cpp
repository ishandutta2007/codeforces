/*
* C++11 code template for contests.
* @author: Andrei Kalendarov
* @e-mail: andreykalendarov@gmail.com
*/

//#define ANDREIKKAA_ALLOCATOR
const int _ML = 228;

const char _inpf[] =
#if defined(ANDREIKKAA)
    "input.txt"
#else
    ""
#endif
;
const char _outf[] =
#if defined(ANDREIKKAA)
    ""
#else
    ""
#endif
;

#if defined(ANDREIKKAA)
#undef NDEBUG
#else
#pragma GCC optimize("O3,no-stack-protector")
#endif
#include <bits/stdc++.h>
#if !defined(ANDREIKKAA)
#define endl '\n'
#endif
#define x first
#define y second
using namespace std;
#define rand abcdefghijklmnopqrstuvwxyz
#define random_shuffle abcdefghijklmnopqrstuvwxyz
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef double ld;
const ld PI = 3.14159265358979323846;
mt19937 rd(228);
#if defined(ANDREIKKAA_ALLOCATOR)
char _mem[_ML * 1024 * 1024];
size_t _ptr = 0;
inline void* operator new (size_t _x) { _ptr += _x; assert(_ptr < _ML * 1024 * 1024); return _mem + _ptr - _x; }
inline void operator delete (void*) { }
#endif
template<class T, class U> inline ostream &operator<< (ostream &, const pair<T, U> &);
template<class T, class U> inline istream &operator>> (istream &, pair<T, U> &);
template<class T> inline ostream &operator<< (ostream &, const vector<T> &);
template<class T> inline istream &operator>> (istream &, vector<T> &);
template<class T> inline ostream &operator<< (ostream &, const set<T> &);
template<class T> inline ostream &operator<< (ostream &, const multiset<T> &);
template<class T> inline ostream &operator<< (ostream &, const unordered_set<T> &);
template<class T> inline ostream &operator<< (ostream &, const unordered_multiset<T> &);
template<class T, class U> inline ostream &operator<< (ostream &, const map<T, U> &);
template<class T, class U> inline ostream &operator<< (ostream &, const unordered_map<T, U> &);

/* ________ CODE ________ */

const int N = 100 * 1000 + 228;

inline void _main_function()
{
    int n;
    cin >> n;

    vector<pair<pair<int, int>, pair<int, int>>> a(n);

    vector<int> nums;

    for(int i = 0; i < n; ++i)
    {
        cin >> a[i].x.x;

        if(a[i].x.x == 1)
        {
            cin >> a[i].x.y;
            nums.push_back(a[i].x.y);
        } else
        {
            cin >> a[i].x.y >> a[i].y.x >> a[i].y.y;
        }
    }

    sort(all(nums));
    nums.erase(unique(all(nums)), nums.end());

    vector<set<int>> pos(N);

    for(int i = 0; i < n; ++i)
    {
        if(a[i].x.x == 1)
        {
            int x = a[i].x.y;
            int lol = (int)(lower_bound(all(nums), x) - nums.begin());
            for(int j = 1; j * j <= x; ++j)
            {
                if(x % j == 0)
                {
                    pos[j].insert(lol);
                    pos[x / j].insert(lol);
                }
            }
        } else
        {
            int x = a[i].x.y;
            int k = a[i].y.x;
            int s = a[i].y.y;

            if(x % k != 0)
            {
                cout << -1 << endl;
                continue;
            }

            int lb = 0;
            int rb = (int)(upper_bound(all(nums), s - x) - nums.begin());
            if(lb == rb)
            {
                cout << -1 << endl;
                continue;
            }

            bool ok = false;
            for(int bt = 16; bt >= 0; --bt)
            {
                if(lb == rb)
                {
                    cout << -1 << endl;
                    ok = true;
                    break;
                }

                int l = lb;
                int r = rb;

                while(l != r)
                {
                    int m = (l + r) / 2;
                    if((nums[m] >> bt) & 1)
                    {
                        r = m;
                    } else
                    {
                        l = m + 1;
                    }
                }

                bool is0 = false;
                auto it = pos[k].lower_bound(lb);
                if(it != pos[k].end() && *it < l) {
                    is0 = true;
                }

                bool is1 = false;
                it = pos[k].lower_bound(l);
                if(it != pos[k].end() && *it < rb) {
                    is1 = true;
                }

                if((x >> bt) & 1)
                {
                    if(is0)
                    {
                        rb = l;
                    }
                    else if(is1)
                    {
                        lb = l;
                    } else
                    {
                        cout << -1 << endl;
                        ok = true;
                        break;
                    }
                } else
                {
                    if(is1)
                    {
                        lb = l;
                    }
                    else if(is0)
                    {
                        rb = l;
                    } else
                    {
                        cout << -1 << endl;
                        ok = true;
                        break;
                    }
                }
            }

            if(ok)
            {
                continue;
            }
            cout << nums[*pos[k].lower_bound(lb)] << endl;
        }
    }
}

/* ________ CODE ________ */

int main()
{
#if defined(ANDREIKKAA)
    time_t _start = clock();
#endif
    if (_inpf[0] != '\0') assert(freopen(_inpf, "r", stdin) != nullptr);
    if (_outf[0] != '\0') assert(freopen(_outf, "w", stdout) != nullptr);
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cout << setprecision(20);
    //cout << fixed;

    _main_function();
#if defined(ANDREIKKAA)
    cout << "Time: " << (clock() - _start) / (ld)CLOCKS_PER_SEC << endl;
#endif
}

template<class T, class U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p)
{
    _out << _p.x << ' ' << _p.y;
    return _out;
}
template<class T, class U> inline istream &operator>> (istream &_in, pair<T, U> &_p)
{
    _in >> _p.x >> _p.y;
    return _in;
}
template<class T> inline ostream &operator<< (ostream &_out, const vector<T> &_v)
{
    if (_v.empty()) { return _out; }
    _out << *_v.begin();
    for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline istream &operator>> (istream &_in, vector<T> &_v)
{
    for (auto &_i : _v) { _in >> _i; }
    return _in;
}
template<class T> inline ostream &operator<< (ostream &_out, const set<T> &_s)
{
    if (_s.empty()) { return _out; }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline ostream &operator<< (ostream &_out, const multiset<T> &_s)
{
    if (_s.empty()) { return _out; }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline ostream &operator<< (ostream &_out, const unordered_set<T> &_s)
{
    if (_s.empty()) { return _out; }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline ostream &operator<< (ostream &_out, const unordered_multiset<T> &_s)
{
    if (_s.empty()) { return _out; }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T, class U> inline ostream &operator<< (ostream &_out, const map<T, U> &_m)
{
    if (_m.empty()) { return _out; }
    _out << '(' << _m.begin()->x << ": " << _m.begin()->y << ')';
    for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->x << ": " << _it->y << ')'; }
    return _out;
}
template<class T, class U> inline ostream &operator<< (ostream &_out, const unordered_map<T, U> &_m)
{
    if (_m.empty()) { return _out; }
    _out << '(' << _m.begin()->x << ": " << _m.begin()->y << ')';
    for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->x << ": " << _it->y << ')'; }
    return _out;
}