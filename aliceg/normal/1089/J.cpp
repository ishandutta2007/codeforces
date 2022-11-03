#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <random>
#include <bitset>
#include <cassert>

#define sqr(x) ((x) * (x))
#define F first
#define S second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
//#define int ll
#define mp(a) make_pair(a)
#define int long long
#ifndef _getchar_nolock
#define _getchar_nolock getchar_unlocked
#define _putchar_nolock putchar_unlocked
#endif

#pragma warning(disable : 4996)
//#pragma comment(linker, "/stack:16777216")
#ifndef LOCAL
#define endl '\n'
#endif

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<char> vc;

const ll INF = 1e18 + 10;
const ld PI = 3.141592653589793;
const ld EPS = 1e-9;
const int N = 1 << 20;

bool is_word(char c) {
    return isdigit(c) || c == '_' || c == '$' || (0 <= c - 'A' && c - 'A' < 26) || (0 <= c - 'a' && c - 'a' < 26);
}

string get_token(string& s, int l, unordered_set<string>& reserved) {
    string token;
    if (isdigit(s[l])) {
        for (int i = l; i < s.length(); ++i) {
            if (!isdigit(s[i]))
                break;
            token += s[i];
        }
    }
    else if (is_word(s[l])) {
        for (int i = l; i < s.length(); ++i) {
            if (!is_word(s[i]))
                break;
            token += s[i];
        }
    }
    string cur;
    for (int i = l; i < min((int)s.length(), l + 20); ++i) {
        if (s[i] == ' ' || s[i] == '#')
            break;
        cur += s[i];
        if (reserved.find(cur) != reserved.end() && cur.length() > token.length())
            token = cur;
    }
    return token;
}

void next_word(string& s, int len) {
    for (int i = len - 1; i >= 0; --i) {
        if (s[i] != 'z') {
            s[i]++;
            for (int j = i + 1; j < len; ++j)
                s[j] = 'a';
            return;
        }
    }
    s = "";
}

void solution() {
    int n;
    cin >> n;
    unordered_set<string> reserved;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        reserved.insert(s);
    }
    int m;
    cin >> m;
    vector<string> tokens;
    for (int t = 0; t < m + 1; ++t) {
        string s;
        getline(cin, s);
        int cur = 0;
        while (cur < s.length() && s[cur] == ' ')
            ++cur;
        while (cur < s.length()) {
            if (s[cur] == '#')
                break;
            tokens.push_back(get_token(s, cur, reserved));
            cur += tokens.back().length();
            while (cur < s.length() && s[cur] == ' ')
                ++cur;
        }
    }
    vi type(tokens.size());
    for (int i = 0; i < tokens.size(); ++i) {
        if (reserved.find(tokens[i]) != reserved.end())
            type[i] = 2;
        else if (isdigit(tokens[i][0]))
            type[i] = 1;
        else
            type[i] = 0;
    }
    vector<string> words;
    unordered_map<string, string> mapp;
    for (int i = 0; i < tokens.size(); ++i) {
        if (type[i] == 0 && mapp.find(tokens[i]) == mapp.end()) {
            words.push_back(tokens[i]);
            mapp[tokens[i]] = "";
        }
    }
    int cur = 0;
    for (int len = 1; cur < words.size(); ++len) {
        string new_word;
        for (int i = 0; i < len; ++i)
            new_word += 'a';
        while (new_word != "" && reserved.find(new_word) != reserved.end())
            next_word(new_word, len);
        while (cur < words.size() && new_word != "") {
            mapp[words[cur]] = new_word;
            do
                next_word(new_word, len);
            while (new_word != "" && reserved.find(new_word) != reserved.end());
            ++cur;
        }
    }
    for (int i = 0; i < tokens.size(); ++i) {
        if (type[i] == 0)
            tokens[i] = mapp[tokens[i]];
    }
    vector<pii> seg;
    for (int i = 0; i < (int)tokens.size() - 1; ++i) {
        int r = -1;
        string cur = tokens[i];
        bool dig = true, wrd = !isdigit(cur[0]);
        for (char c : cur) {
            if (!isdigit(c))
                dig = false;
            if (!is_word(c))
                wrd = false;
        }
        if ((dig && isdigit(tokens[i + 1][0])) || (wrd && is_word(tokens[i + 1][0])))
            r = i + 1;
        else {
            int j = i + 1;
            bool found = false;
            while (!found && cur.size() <= 20 && j < tokens.size()) {
                for (int x = 0; x < tokens[j].size() && cur.size() <= 20; ++x) {
                    cur += tokens[j][x];
                    if (reserved.find(cur) != reserved.end()) {
                        found = true;
                        r = j;
                        break;
                    }
                }
                ++j;
            }
        }
        if (r != -1) {
            seg.push_back({ i, i + 1 });
            seg.push_back({ r, -i -1 });
        }
    }
    sort(all(seg));
    vc is_space((int)tokens.size());
    set<int> open;
    for (int i = 0; i < seg.size(); ++i) {
        if (seg[i].second > 0)
            open.insert(seg[i].second);
        else if (open.find(-seg[i].second) != open.end()) {
            is_space[seg[i].first - 1] = 1;
            open.clear();
        }
    }
    for (int i = 0; i < tokens.size(); ++i) {
        cout << tokens[i];
        if (is_space[i])
            cout << ' ';
    }
}

signed main() {
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));
#endif
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; ++i)
        solution();
    
    return 0;
}