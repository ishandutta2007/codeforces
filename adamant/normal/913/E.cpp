#include <bits/stdc++.h>

using namespace std;

vector<pair<string, int>> gen_f(int n);

vector<pair<string, int>> ans_t[40], ans_e[40], ans_f[40];

vector<pair<string, int>> sparse(vector<pair<string, int>> g) {
    string gg[256];
    int used[256] = {0};
    vector<pair<string, int>> res;
    for(auto it: g) {
        if(!used[it.second]) {
            used[it.second] = true;
            gg[it.second] = it.first;
        } else {
            gg[it.second] = min(gg[it.second], it.first);
        }
    }
    for(int i = 0; i < 256; i++) {
        if(gg[i].size()) {
            res.push_back({gg[i], i});
        }
    }
    return res;
}

vector<pair<string, int>> gen_t(int n) {
    if(ans_t[n].size()) {
        return ans_t[n];
    }
    auto ret = gen_f(n);
    if(n > 2) {
        for(int i = 1; n - i - 1 > 0; i++) {
            auto x = gen_t(i);
            auto y = gen_f(n - i - 1);
            for(auto it: x) {
                for(auto jt: y) {
                    ret.push_back({it.first + "&" + jt.first, it.second & jt.second});
                }
            }
        }
    }
    return ans_t[n] = sparse(ret);
}

vector<pair<string, int>> gen_e(int n) {
    if(ans_e[n].size()) {
        return ans_e[n];
    }
    auto ret = gen_t(n);
    if(n > 2) {
        for(int i = 1; n - i - 1 > 0; i++) {
            auto x = gen_e(i);
            auto y = gen_t(n - i - 1);
            for(auto it: x) {
                for(auto jt: y) {
                    ret.push_back({it.first + "|" + jt.first, it.second | jt.second});
                }
            }
        }
    }
    return ans_e[n] = sparse(ret);
}

string get_tab(string f);

vector<pair<string, int>> gen_f(int n) {
    if(ans_f[n].size()) {
        return ans_f[n];
    }
    if(n == 1) {
        return {{"x", bitset<8>(get_tab("x")).to_ulong()}, {"y", bitset<8>(get_tab("y")).to_ulong()}, {"z", bitset<8>(get_tab("z")).to_ulong()}};
    }
    vector<pair<string, int>> ret;
    { // ! A
        auto gg = gen_f(n - 1);
        for(auto it: gg) {
            ret.push_back({"!" + it.first, ((1 << 8) - 1) ^ it.second});
        }
    } { // ( A )
        if(n > 2) {
            auto gg = gen_e(n - 2);
            for(auto it: gg) {
                ret.push_back({"(" + it.first + ")", it.second});
            }
        }
    }
    return ans_f[n] = sparse(ret);
}

int parse_f(string &f, int x, int y, int z);

int parse_t(string &f, int x, int y, int z) {
    int s = parse_f(f, x, y, z);
    if(!f.empty() && f.back() == '&') {
        f.pop_back();
        s &= parse_t(f, x, y, z);
    }
    return s;
}

int parse_e(string &f, int x, int y, int z) {
    int s = parse_t(f, x, y, z);
    if(!f.empty() && f.back() == '|') {
        f.pop_back();
        s |= parse_e(f, x, y, z);
    }
    return s;
}

int parse_f(string &f, int x, int y, int z) {
    if(f.back() == '!') {
        f.pop_back();
        return !parse_f(f, x, y, z);
    }
    if(f.back() == '(') {
        f.pop_back();
        int s = parse_e(f, x, y, z);
        f.pop_back();
        return s;
    }
    if(f.back() == 'x') {
        f.pop_back();
        return x;
    } else if(f.back() == 'y') {
        f.pop_back();
        return y;
    } else {
        f.pop_back();
        return z;
    }
}

string get_tab(string f) {
    reverse(begin(f), end(f));
    string res;
    string t;
    t = f; res += char('0' + parse_e(t, 0, 0, 0));
    t = f; res += char('0' + parse_e(t, 0, 0, 1));
    t = f; res += char('0' + parse_e(t, 0, 1, 0));
    t = f; res += char('0' + parse_e(t, 0, 1, 1));
    t = f; res += char('0' + parse_e(t, 1, 0, 0));
    t = f; res += char('0' + parse_e(t, 1, 0, 1));
    t = f; res += char('0' + parse_e(t, 1, 1, 0));
    t = f; res += char('0' + parse_e(t, 1, 1, 1));
    return res;
}

vector<pair<string, int>> func;

string ANS[] = {
"!x&x",
"x&y&z",
"!z&x&y",
"x&y",
"!y&x&z",
"x&z",
"!y&x&z|!z&x&y",
"(y|z)&x",
"!y&!z&x",
"!y&!z&x|x&y&z",
"!z&x",
"!z&x|x&y",
"!y&x",
"!y&x|x&z",
"!(y&z)&x",
"x",
"!x&y&z",
"y&z",
"!x&y&z|!z&x&y",
"(x|z)&y",
"!x&y&z|!y&x&z",
"(x|y)&z",
"!x&y&z|!y&x&z|!z&x&y",
"(x|y)&z|x&y",
"!x&y&z|!y&!z&x",
"!y&!z&x|y&z",
"!x&y&z|!z&x",
"!z&x|y&z",
"!x&y&z|!y&x",
"!y&x|y&z",
"!(y&z)&x|!x&y&z",
"x|y&z",
"!x&!z&y",
"!x&!z&y|x&y&z",
"!z&y",
"!z&y|x&y",
"!x&!z&y|!y&x&z",
"!x&!z&y|x&z",
"!y&x&z|!z&y",
"!z&y|x&z",
"!(!x&!y|x&y|z)",
"!(!x&!y|x&y|z)|x&y&z",
"!z&(x|y)",
"!z&(x|y)|x&y",
"!x&!z&y|!y&x",
"!x&!z&y|!y&x|x&z",
"!y&x|!z&y",
"!z&y|x",
"!x&y",
"!x&y|y&z",
"!(x&z)&y",
"y",
"!x&y|!y&x&z",
"!x&y|x&z",
"!(x&z)&y|!y&x&z",
"x&z|y",
"!x&y|!y&!z&x",
"!x&y|!y&!z&x|y&z",
"!x&y|!z&x",
"!z&x|y",
"!x&y|!y&x",
"!x&y|!y&x|x&z",
"!(x&z)&y|!y&x",
"x|y",
"!x&!y&z",
"!x&!y&z|x&y&z",
"!x&!y&z|!z&x&y",
"!x&!y&z|x&y",
"!y&z",
"!y&z|x&z",
"!y&z|!z&x&y",
"!y&z|x&y",
"!(!x&!z|x&z|y)",
"!(!x&!z|x&z|y)|x&y&z",
"!x&!y&z|!z&x",
"!x&!y&z|!z&x|x&y",
"!y&(x|z)",
"!y&(x|z)|x&z",
"!y&z|!z&x",
"!y&z|x",
"!x&z",
"!x&z|y&z",
"!x&z|!z&x&y",
"!x&z|x&y",
"!(x&y)&z",
"z",
"!(x&y)&z|!z&x&y",
"x&y|z",
"!x&z|!y&!z&x",
"!x&z|!y&!z&x|y&z",
"!x&z|!z&x",
"!x&z|!z&x|x&y",
"!x&z|!y&x",
"!y&x|z",
"!(x&y)&z|!z&x",
"x|z",
"!(!y&!z|x|y&z)",
"!(!y&!z|x|y&z)|x&y&z",
"!x&!y&z|!z&y",
"!x&!y&z|!z&y|x&y",
"!x&!z&y|!y&z",
"!x&!z&y|!y&z|x&z",
"!y&z|!z&y",
"!y&z|!z&y|x&y",
"!(!x&!y|x&y|z)|!x&!y&z",
"!(!x&!y|x&y|z)|!x&!y&z|x&y&z",
"!x&!y&z|!z&(x|y)",
"!x&!y&z|!z&(x|y)|x&y",
"!x&!z&y|!y&(x|z)",
"!x&!z&y|!y&(x|z)|x&z",
"!y&(x|z)|!z&y",
"!y&z|!z&y|x",
"!x&(y|z)",
"!x&(y|z)|y&z",
"!x&z|!z&y",
"!x&z|y",
"!x&y|!y&z",
"!x&y|z",
"!(x&y)&z|!z&y",
"y|z",
"!x&(y|z)|!y&!z&x",
"!x&(y|z)|!y&!z&x|y&z",
"!x&(y|z)|!z&x",
"!x&z|!z&x|y",
"!x&(y|z)|!y&x",
"!x&y|!y&x|z",
"!x&y|!y&z|!z&x",
"x|y|z",
"!(x|y|z)",
"!(x|y|z)|x&y&z",
"!(!x&y|!y&x|z)",
"!(x|y|z)|x&y",
"!(!x&z|!z&x|y)",
"!(x|y|z)|x&z",
"!(!x&y|!y&x|z)|!y&x&z",
"!(x|y|z)|(y|z)&x",
"!y&!z",
"!y&!z|x&y&z",
"!(!x&y|z)",
"!y&!z|x&y",
"!(!x&z|y)",
"!y&!z|x&z",
"!(!x&y|z)|!y&x",
"!y&!z|x",
"!(!y&z|!z&y|x)",
"!(x|y|z)|y&z",
"!(!x&y|!y&x|z)|!x&y&z",
"!(x|y|z)|(x|z)&y",
"!(!x&z|!z&x|y)|!x&y&z",
"!(x|y|z)|(x|y)&z",
"!(!x&y|!y&x|z)|!x&y&z|!y&x&z",
"!(x|y|z)|(x|y)&z|x&y",
"!x&y&z|!y&!z",
"!y&!z|y&z",
"!(!x&y|z)|!x&y&z",
"!(!x&y|z)|y&z",
"!(!x&z|y)|!x&y&z",
"!(!x&z|y)|y&z",
"!(!x&y|z)|!x&y&z|!y&x",
"!y&!z|x|y&z",
"!x&!z",
"!x&!z|x&y&z",
"!(!y&x|z)",
"!x&!z|x&y",
"!x&!z|!y&x&z",
"!x&!z|x&z",
"!(!y&x|z)|!y&x&z",
"!(!y&x|z)|x&z",
"!(x&y|z)",
"!(x&y|z)|x&y&z",
"!z",
"!z|x&y",
"!x&!z|!y&x",
"!(x&y|z)|x&z",
"!y&x|!z",
"!z|x",
"!(!y&z|x)",
"!x&!z|y&z",
"!(!y&x|z)|!x&y",
"!x&!z|y",
"!(!y&z|x)|!y&x&z",
"!(!y&z|x)|x&z",
"!(!y&x|z)|!x&y|!y&x&z",
"!x&!z|x&z|y",
"!x&y|!y&!z",
"!(x&y|z)|y&z",
"!x&y|!z",
"!z|y",
"!(!x&!y&z|x&y)",
"!x&!z|!y&x|y&z",
"!x&y|!y&x|!z",
"!z|x|y",
"!x&!y",
"!x&!y|x&y&z",
"!x&!y|!z&x&y",
"!x&!y|x&y",
"!(!z&x|y)",
"!x&!y|x&z",
"!(!z&x|y)|!z&x&y",
"!(!z&x|y)|x&y",
"!(x&z|y)",
"!(x&z|y)|x&y&z",
"!x&!y|!z&x",
"!(x&z|y)|x&y",
"!y",
"!y|x&z",
"!y|!z&x",
"!y|x",
"!(!z&y|x)",
"!x&!y|y&z",
"!(!z&y|x)|!z&x&y",
"!(!z&y|x)|x&y",
"!(!z&x|y)|!x&z",
"!x&!y|z",
"!(!z&x|y)|!x&z|!z&x&y",
"!x&!y|x&y|z",
"!x&z|!y&!z",
"!(x&z|y)|y&z",
"!(!x&!z&y|x&z)",
"!x&!y|!z&x|y&z",
"!x&z|!y",
"!y|z",
"!x&z|!y|!z&x",
"!y|x|z",
"!(x|y&z)",
"!(x|y&z)|x&y&z",
"!x&!y|!z&y",
"!(x|y&z)|x&y",
"!x&!z|!y&z",
"!(x|y&z)|x&z",
"!(!y&!z&x|y&z)",
"!x&!y|!z&y|x&z",
"!((x|y)&z|x&y)",
"!((x|y)&z|x&y)|x&y&z",
"!x&!y|!z",
"!x&!y|!z|x&y",
"!x&!z|!y",
"!x&!z|!y|x&z",
"!y|!z",
"!y|!z|x",
"!x",
"!x|y&z",
"!x|!z&y",
"!x|y",
"!x|!y&z",
"!x|z",
"!x|!y&z|!z&y",
"!x|y|z",
"!x|!y&!z",
"!x|!y&!z|y&z",
"!x|!z",
"!x|!z|y",
"!x|!y",
"!x|!y|z",
"!(x&y&z)",
"!x|x",
};

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*int have = 0, need = 256;
    string ans[256];
    int cur = 1;
    while(have < need) {
        auto x = gen_e(cur);
        for(auto it: x) {
            if(ans[it.second].empty()) {
                ans[it.second] = it.first;
                have++;
            }
        }
        cur++;
    }
    for(int i = 0; i < 256; i++) {
        cout << "\"" << ans[i] << "\"," << endl;
        if(ans[i].size() > 0) {
            assert(bitset<8>(get_tab(ans[i])).to_ulong() == i);
        }
    }*/
    
    int n;
    cin >> n;
    while(n--) {
        string t;
        cin >> t;
        cout << ANS[bitset<8>(t).to_ulong()] << endl;
    }
    return 0;
}