#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline char ask1(int i) {
    cout << "? 1 " << i + 1 << endl;
    char ans;
    cin >> ans;
    return ans;
}

inline int ask2(int l, int r) {
    cout << "? 2 " << l + 1 << " " << r + 1 << endl;
    int ans;
    cin >> ans;
    return ans;
}

signed main(){
    int n;
    cin >> n;
    string s;
    vector <pair <int, char>> cur;
    for (int r = 0; r < n; ++r) {
        int l_b = -1, r_b = (int)cur.size();
        while (r_b - l_b > 1) {
            int m_b = (l_b + r_b) / 2;
            if (ask2(cur[m_b].first, r) == (int)cur.size() - m_b) l_b = m_b;
            else r_b = m_b;
        }
        if (l_b == -1) {
            char c = ask1(r);
            s.push_back(c);
            cur.emplace_back(r, c);
        } else {
            char c = cur[l_b].second;
            s.push_back(c);
            cur.erase(cur.begin() + l_b);
            cur.emplace_back(r, c);
        }
    }
    cout << "! " << s << endl;
}