// 2018, Sayutin Dmitry.

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;

using std::pair;
using std::make_pair;

using std::min;
using std::abs;
using std::max;

using std::unique;
using std::sort;
using std::generate;
using std::reverse;
using std::min_element;
using std::max_element;

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

template <typename T>
T input() {
    T res;
    cin >> res;
    LASSERT(cin);
    return res;
}

template <typename IT>
void input_seq(IT b, IT e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()

#define pb push_back
#define eb emplace_back

const int max_n = 100;
int64_t dp[max_n + 5][max_n + 5][max_n + 5];

vector<int> get_pi(const string& s) {
    vector<int> res(SZ(s), 0);

    for (int i = 1; i != SZ(s); ++i) {
        int k = res[i - 1];
        
        while (k != -1 and s[i] != s[k])
            k = (k == 0 ? -1 : res[k - 1]);

        res[i] = k + 1;
    }
    return res;
}

int64_t solve(const string& s, int n) {        
    vector<int> pi = get_pi(s);

    vector<int> go[2];
    go[0] = go[1] = vector<int>(SZ(s) + 1, -1);
    
    go[0][SZ(s)] = go[1][SZ(s)] = SZ(s);

    go[s[0] - '0'][0] = 1;
    go[(s[0] - '0') ^ 1][0] = 0;
    
    for (int i = 1; i != SZ(s); ++i) {
        int alp = s[i] - '0';
        go[alp][i] = i + 1;
        go[alp ^ 1][i] = go[alp ^ 1][pi[i - 1]];
    }

    // (state_fin, len, go(state_fin, cur_prefix), go(0, cur_prefix))

    int64_t ans = 0;
    for (int state_fin = 0; state_fin <= SZ(s); ++state_fin) {
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= SZ(s); ++j)
                for (int k = 0; k <= SZ(s); ++k)
                    dp[i][j][k] = 0;

        auto next = [&](int i, int j, int k, int64_t val) {
            dp[i][j][k] += val;
        };
        
        dp[0][state_fin][0] = 1;
        for (int len = 0; len < n; ++len)
            for (int st1 = 0; st1 <= SZ(s); ++st1)
                for (int st2 = 0; st2 <= SZ(s); ++st2) {
                    next(len + 1, go[0][st1], go[0][st2], dp[len][st1][st2]);
                    next(len + 1, go[1][st1], go[1][st2], dp[len][st1][st2]);
                }


        ans += dp[n][SZ(s)][state_fin];
    }

    return ans;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n = input<int>();
    string s = input<string>();
        
    
    cout << solve(s, n) << "\n";
    
    return 0;
}