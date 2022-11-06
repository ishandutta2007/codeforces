//#pragma GCC optimize("Ofast")
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#define int long long
#define ld long double
#define pb push_back
//#define long long int
using namespace std;
const int maxn = 5001000, maxc = 22, maxv = 100, mod = 1e9 + 7, maxa = 1005, maxs = 820, maxb = 10, base = 737, base2 = 3079, mod3 = 998244353, delt = 10513;
const long long inf = 2e16;
const int infint = 1e9 + 11;
long long max(long long x, long long y){return (x > y ? x : y);}
long long min(long long x, long long y){return (x < y ? x : y);}

int ans[maxn];
int ph[maxn];

int32_t main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int h1 = 0;
    int h2 = 0;
    int basep = 1;
    int res = 0;
    int n = s.size();
    for(int i = 1; i <= n; i++)
    {
        h1 += (basep * (s[i - 1] - 'a')) % mod;
        h1 %= mod;
        h2 = ((h2 * base) % mod) + (s[i - 1] - 'a');
        h2 %= mod;
        basep *= base;
        basep %= mod;
        if(h1 == h2)
        {
            ans[i] = ans[i / 2] + 1;
        }
        res += ans[i];
    }
    
    cout << res << endl;

    return 0;
}