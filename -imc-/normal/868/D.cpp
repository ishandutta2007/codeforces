#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

const int MAX_ANS = 16;

struct Str {
    array<set<int>, MAX_ANS + 1> masks;
    int len;
    int prefix;
    int suffix;
    
    int answer;
    
    void calc_answer() {
        for (int i = answer + 1; i <= MAX_ANS; i++) {
            bool fail = false;
            
            for (int j = 0; j < (1 << i); j++)
                if (!masks[i].count(j)) {
                    fail = true;
                    break;
                }
                
            if (!fail) {
                answer = i;
            }
            else break;
        }
    }
    
    void init(string s) {
        len = s.length();
        prefix = suffix = 0;
        int cut = min(len, MAX_ANS);
        
        for (int i = 0; i < cut; i++) {
            if (s[i] == '1')
                prefix |= (1 << i);
            
            if (s[s.length() - cut + i] == '1') {
                suffix |= (1 << i);
            }
        }
        
        for (int l = 1; l <= min(len, MAX_ANS); l++) {
            for (int i = 0; i + l - 1 < len; i++) {
                int mask = 0;
                for (int j = 0; j < l; j++)
                    if (s[i + j] == '1')
                        mask |= 1 << j;
                    
                masks[l].insert(mask);
            }
        }
        
        answer = 0;
        calc_answer();
    }
    
    int suffix_len() {
        return min(len, MAX_ANS);
    }
    
    void print(string base) {
        printf("string %s:\n", base.c_str());
        printf("prefix: "); for (int i = 0; i < min(len, MAX_ANS); i++) printf("%d", prefix & (1 << i) ? 1 : 0); printf("\n");
        printf("suffix: "); for (int i = 0; i < min(len, MAX_ANS); i++) printf("%d", suffix & (1 << i) ? 1 : 0); printf("\n");
        for (int i = 1; i <= MAX_ANS; i++)
            if (!masks[i].empty()) {
                printf("len %d:\n", i);
                for (int x: masks[i]) {
                    for (int j = 0; j < i; j++)
                        if (x & (1 << j))
                            printf("1");
                        else
                            printf("0");
                    printf("\n");
                }
            }
    }
};

Str combine(Str a, Str b) {
    Str res;
    res.masks = a.masks;
    for (int i = 0; i <= MAX_ANS; i++)
        for (int x: b.masks[i])
            res.masks[i].insert(x);
    
    res.len = a.len + b.len;
    res.len = min(res.len, 3 * MAX_ANS);
    
    //res.prefix = (a.prefix + ((li)b.prefix << b.len)) & ((1 << MAX_ANS) - 1);
    //res.suffix = (a.suffix >> (MAX_ANS - b.suffix_len()));
    //res.suffix = (a.prefix + ((li)b.prefix << b.len)) & ((1 << MAX_ANS) - 1);
    
    res.prefix = a.prefix;
    if (a.len < MAX_ANS)
        for (int i = 0; i < min(b.len, MAX_ANS - a.len); i++)
            if (b.prefix & (1 << i))
                res.prefix |= 1 << (a.len + i);
            
    res.suffix = b.suffix;
    if (b.len < MAX_ANS)
        for (int i = 0; i < min(a.len, MAX_ANS - b.len); i++) {
            res.suffix <<= 1;
            if (a.suffix & (1 << (min(a.len, MAX_ANS) - 1 - i)))
                res.suffix |= 1;
        }
    
    for (int inter_len = 1; inter_len <= min(MAX_ANS, a.len + b.len); inter_len++) {
        int asl = min(MAX_ANS, a.len);
        for (int n_suffix = 0; n_suffix <= min(asl, inter_len); n_suffix++) {
            if (inter_len - n_suffix > b.len) continue;
            int new_mask = ((a.suffix >> (asl - n_suffix)) & ((1 << n_suffix) - 1)) + (((b.prefix) & ((1 << max(inter_len - n_suffix, 0)) - 1)) << n_suffix);
            res.masks[inter_len].insert(new_mask);
            //printf("inter mask length %d -> ", inter_len); for (int i = 0; i < inter_len; i++) printf("%d", new_mask & (1 << i) ? 1 : 0); printf("\n");
        }
    }
    
    res.answer = max(a.answer, b.answer);
    res.calc_answer();
    
    return res;
}

int dumb(string s) {
    for (int l = 1; l <= s.length(); l++) {
        set<int> have;
        for (int j = 0; j + l - 1 < s.length(); j++) {
            int mask = 0;
            for (int k = 0; k < l; k++)
                if (s[j + k] == '1')
                    mask |= 1 << k;
            have.insert(mask);
        }
        
        if (have.size() < (1 << l))
            return min(l - 1, MAX_ANS);
    }
    abort();
}

void solve(bool read) {
    int n;
    if (read)
        cin >> n;
    else {
        n = 5;
        printf("%d\n", n);
    }
    
    vector<Str> masks(n);
    
    vector<string> u(n);
    for (int i = 0; i < n; i++) {
        string s;
        if (read)
            cin >> s;
        else {
            int l = rand() % 5 + 1; 
            for (int i = 0; i < l; i++)
                s += "01"[rand() % 2];
            printf("%s\n", s.c_str());
        }
        masks[i].init(s);
        u[i] = s;
        
        //masks[i].print(u[i]);
    }
    
    //printf("\n\nGO\n\n");
    
    int nq;
    if (read)
        cin >> nq;
    else {
        nq = 20;
        printf("%d\n", nq);
    }
    
    for (int i = 0; i < nq; i++) {
        int a, b;
        if (read) {
            cin >> a >> b;
            a--; b--;
        }
        else {
            a = rand() % (n + i);
            b = rand() % (n + i);
            printf("%d %d\n", a + 1, b + 1);
        }
        
        auto res = combine(masks[a], masks[b]);
        masks.push_back(res);
        
        cout << res.answer << "\n";
        //string xu = u[a] + u[b];
        
        //res.print(xu);
        
        //u.push_back(xu);
        //printf("answer: %d, expected: %d\n", res.answer, dumb(xu));
        
        //assert(dumb(xu) == res.answer);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
#if 0
    while (true) {
        //guessed = false;
        solve(false);
        //assert(guessed);
    }
#endif
    
    return 0;
}