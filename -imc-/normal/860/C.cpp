#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

int get_num(string s) {
    istringstream is(s);
    int x;
    if ((is >> x) && to_string(x) == s)
        return x;
    
    return -1;
}

void solve(bool read) {
    int n;
    cin >> n;
    
    vector<pair<string, int>> s(n);
    int n_e = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i].first >> s[i].second;
        if (s[i].second) n_e++;
    }
    
    set<string> non_e, non_t, non_num_e, non_num_t;
    
    set<int> e_slots, t_slots;
    
    for (int i = 1; i <= n_e; i++) e_slots.insert(i);
    for (int i = n_e + 1; i <= n; i++) t_slots.insert(i);
    
    set<string> all_s;
    
    for (int i = 0; i < n; i++) {
        int num = get_num(s[i].first);
        all_s.insert(s[i].first);
        
        if (s[i].second == 1) {
            if (num >= 1 && num <= n_e) {
                e_slots.erase(num);
                continue;
            }
            
            if (num > n_e && num <= n) {
                non_e.insert(s[i].first);
                t_slots.erase(num);
            }
            else
                non_num_e.insert(s[i].first);
        }
        else {
            if (num > n_e && num <= n) {
                t_slots.erase(num);
                continue;
            }
            
            if (num >= 1 && num <= n_e) {
                non_t.insert(s[i].first);
                e_slots.erase(num);
            }
            else
                non_num_t.insert(s[i].first);
        }
    }
    
    string rnd = "";
    while (true) {
        rnd = "";
        for (int i = 0; i < 6; i++)
            rnd += 'a' + rand() % 26;
        
        if (!all_s.count(rnd))
            break;
    }
    
    vector<string> answer;
    
    if (e_slots.empty() && t_slots.empty()) {
        assert(non_num_t.empty() && non_num_e.empty());
        
        if (!non_t.empty()) {
            assert(!non_e.empty());
            
            string test = *non_t.begin(); non_t.erase(non_t.begin());
            e_slots.insert(get_num(test));
            //string ex = *non_e.begin(); non_e.erase(non_e.begin());
            
            answer.push_back("move " + test + " " + rnd);
            non_num_t.insert(rnd);
        }
    }
    
    if (!e_slots.empty() || !t_slots.empty()) {
        while (!e_slots.empty() || !t_slots.empty()) {
#if 0
            for (string s: answer)
                printf("%s\n", s.c_str());
            printf("e_slots: "); for (int x: e_slots) printf("%d ", x); printf("\n");
            printf("t_slots: "); for (int x: t_slots) printf("%d ", x); printf("\n");
#endif
            
            if (!e_slots.empty()) {
                if (!non_e.empty()) {
                    answer.push_back("move " + *non_e.begin() + " " + to_string(*e_slots.begin()));
                    t_slots.insert(get_num(*non_e.begin()));
                    non_e.erase(non_e.begin());
                    e_slots.erase(e_slots.begin());
                    continue;
                }
                
                if (!non_num_e.empty()) {
                    answer.push_back("move " + *non_num_e.begin() + " " + to_string(*e_slots.begin()));
                    non_num_e.erase(non_num_e.begin());
                    e_slots.erase(e_slots.begin());
                    continue;
                }
            }
            
            if (!t_slots.empty()) {
                if (!non_t.empty()) {
                    answer.push_back("move " + *non_t.begin() + " " + to_string(*t_slots.begin()));
                    e_slots.insert(get_num(*non_t.begin()));
                    non_t.erase(non_t.begin());
                    t_slots.erase(t_slots.begin());
                    continue;
                }
                
                if (!non_num_t.empty()) {
                    answer.push_back("move " + *non_num_t.begin() + " " + to_string(*t_slots.begin()));
                    non_num_t.erase(non_num_t.begin());
                    t_slots.erase(t_slots.begin());
                    continue;
                }
            }
        }
        
        assert(non_num_e.empty() && non_num_t.empty() && non_t.empty() && non_e.empty());
    }
    
    printf("%d\n", (int)answer.size());
    for (string s: answer)
        printf("%s\n", s.c_str());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    return 0;
}