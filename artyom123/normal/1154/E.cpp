#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb emplace_back
#define all(x) (x).begin(), (x).end

struct student{
    int ind, val;
    student *left, *right;
    student(){}
    student(int _val, int _ind) {
        val = _val;
        ind = _ind;
        left = right = nullptr;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &c : a) {
        cin >> c;
    }
    set<pair<int, student*>> s;
    vector<student*> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = new student(a[i], i);
        if (i > 0) {
            b[i - 1]->right = b[i];
            b[i]->left = b[i - 1];
        }
    }
    for (auto &c : b) {
        s.insert({c->val, c});
    }
    vector <int> ans(n);
    int cur = 1;
    while (s.size()) {
        student *now = s.rbegin()->se;
        s.erase({now->val, now});
        ans[now->ind] = cur;
        student *tmp = now->left;
        for (int i = 0; i < k && tmp != nullptr; i++) {
            ans[tmp->ind] = cur;
            s.erase({tmp->val, tmp});
            tmp = tmp->left;
        }
        student *tmp1 = now->right;
        for (int i = 0; i < k && tmp1 != nullptr; i++) {
            ans[tmp1->ind] = cur;
            s.erase({tmp1->val, tmp1});
            tmp1 = tmp1->right;
        }
        if (tmp != nullptr) {
            tmp->right = tmp1;
        }
        if (tmp1 != nullptr) {
            tmp1->left = tmp;
        }
        cur = 3 - cur;
    }
    for (auto &c : ans) {
        cout << c;
    }
    return 0;
}