#include <iostream>
#include <iterator>
#include <set>
#include <map>
#include <string>
#include <vector>
using namespace std;
const int N = 1e5;
pair<string, string> a[N];
map<string, int> l, r;
map<int, string> rev;
set<int> b[N];
struct node {
    map<int, node*> to;
    vector<int> en;
};
node root;
vector<vector<int> > ans;

inline void add(set<int> &s, int ind) {
    set<int> :: iterator it = s.begin();
    node *cur = &root;
    while(true) {
        if((*cur).to.count(*it) == 0)
            (*cur).to[*it] = new node;
        cur = (*cur).to[*it];
        it++;
        if(it == s.end()) {
            (*cur).en.push_back(ind);
            break;
        }
    }
}

inline void gotrie(node *cur) {
    if((*cur).en.size() > 1)
        ans.push_back((*cur).en);
    for(map<int, node*> :: iterator it = (*cur).to.begin(); it != (*cur).to.end(); it++)
        gotrie((*it).second);
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        s += '/';
        int cnt = 0;
        for(int j = 0, d = s.length(); j < d; j++) {
            if(s[j] == '/')
                cnt++;
            if(cnt == 3) {
                a[i].first = s.substr(0, j);
                l[a[i].first];
                a[i].second = s.substr(j);
                r[a[i].second];
                break;
            }
        }
    }
    int cnt = 0;
    for(map<string, int> :: iterator it = l.begin(); it != l.end(); it++) {
        (*it).second = cnt++;
        rev[(*it).second] = (*it).first;
    }
    cnt = 0;
    for(map<string, int> :: iterator it = r.begin(); it != r.end(); it++)
        (*it).second = cnt++;
    for(int i = 0; i < n; i++)
        b[l[a[i].first]].insert(r[a[i].second]);
    for(int i = 0, sz = (int)l.size(); i < sz; i++)
        add(b[i], i);
    gotrie(&root);
    cout << ans.size() << "\n";
    for(int i = 0, sz = (int)ans.size(); i < sz; i++, cout << "\n")
        for(int j = 0, szj = (int)ans[i].size(); j < szj; j++)
            cout << rev[ans[i][j]] << " ";
    return 0;
}