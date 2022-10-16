#include <iostream>
#include <string>

using namespace std;

pair< pair<bool, bool>, bool> process(const string &s, size_t &pos) {
    if(s[pos] == '(') {
        pos++;
        pair< pair<bool, bool>, bool> l = process(s, pos);
        char op = s[pos];
        pos++;
        pair< pair<bool, bool>, bool> r = process(s, pos);
        pos++;
        if(op == '|')
            return make_pair(make_pair(l.first.first && r.first.first,
                                       l.first.second || r.first.second ||
                                       (l.second && r.second)),
                             (l.second && r.second) ||
                             (l.second && r.first.first) ||
                             (l.first.first && r.second));
        if(op == '&')
            return make_pair(make_pair(l.first.first || r.first.first ||
                                       (l.second && r.second),
                                       l.first.second && r.first.second),
                             (l.second && r.second) ||
                             (l.second && r.first.second) ||
                             (l.first.second && r.second));
        return make_pair(make_pair((l.first.first && r.first.first) ||
                                   (l.first.second && r.first.second) ||
                                   (l.second && r.second),
                                   (l.first.first && r.first.second) ||
                                   (l.first.second && r.first.first) ||
                                   (l.second && r.second)),
                         (l.second && (r.first.first || r.first.second)) ||
                         (r.second && (l.first.first || l.first.second)));
    }
    char c = s[pos];
    pos++;
    if(c == '0')
        return make_pair(make_pair(true, false), false);
    if(c == '1')
        return make_pair(make_pair(false, true), false);
    return make_pair(make_pair(false, false), true);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    size_t pos = 0;
    pair< pair<bool, bool>, bool> ans = process(s, pos);
    cout << (ans.second? "YES" : "NO") << '\n';
    return 0;
}