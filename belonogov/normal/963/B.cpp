#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

const int MOD = 1e9 + 9;


int main() {
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif 

    int n;
    scanf("%d", &n);
    vector<vector<int>> e(n);
    int root = -1;
    for (int i = 0; i < n; i++) {
        int p;
        scanf("%d", &p);
        if (p == 0) {
            root = i;
        }
        else {
            p--;
            e[p].push_back(i);
            e[i].push_back(p);
        }
    }
    //vector<int> use(n);
    vector<int> answer;
    auto merge = [&](deque<int>* a, deque<int>*b) {
        if (a->size() < b->size()) {
            swap(a, b);
        }   
        for (auto x: *b) {
            a->push_back(x);
        }
        delete b;
        return a;
    };

    function<deque<int>*(int, int)> dfs = [&](int v, int p) {
        int cnt = 0;
        deque<int>* ord = new deque<int>();
        for (auto u: e[v]) {
            if (u == p) {
                cnt++;
            }
            else {
                auto res = dfs(u, v);
                if (!res->empty()) {
                    ord = merge(ord, res);
                    cnt++;
                }
            }
        }
        if (cnt % 2 == 0) {
            answer.push_back(v);
            for (auto x: *ord) {
                answer.push_back(x);
            }
            ord->clear();
            return ord;
        }
        else {
            ord->push_front(v);
            return ord;
        }

    };

    auto tmp = dfs(root, -1);
    delete tmp;

    if ((int)answer.size() == n) {
        puts("YES");
        for (auto x: answer) {
            printf("%d\n", x + 1);
        }
    }
    else {
        puts("NO");
    }

}