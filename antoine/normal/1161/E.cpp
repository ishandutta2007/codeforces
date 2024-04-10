#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 1e5 + 9;
int n;
bool eq[MxN + 9];
int color[MxN + 9];

string query(const vector<pair<int, int>> &v) {
    if (v.empty())
        return "";
    cout << "Q " << v.size();
    for (const pair<int, int> &p : v) {
        assert(1 <= p.first && p.first <= n);
        assert(1 <= p.second && p.second <= n);
        cout << ' ' << p.first << ' ' << p.second;
    }
    cout << endl;

    string resp;

    assert(resp != "-1");
    cin >> resp;
    return resp;
}

void f() {
    cin >> n;

    memset(eq, 0, sizeof eq);
    memset(color, 0, sizeof color);

    for (int rep = 0; rep < 2; ++rep) {
        vector<pair<int, int>> pairs;
        for (int i = 1 + rep; i < n; i += 2)
            pairs.emplace_back(i, i + 1);

        const string resp = query(pairs);
        auto it = resp.begin();
        for (int i = 1 + rep; i < n; i += 2)
            eq[i] = *(it++) == '1';
    }


    vector<int> labels = {1};
    for (int i = 2; i <= n; ++i)
        if (!eq[i - 1])
            labels.push_back(i);


    const string resp = [&]() {
        vector<pair<int, int>> pairs1, pairs2;
        for (int i = 2; i < (int) labels.size(); ++i)
            ((i & 2) != 0 ? pairs1 : pairs2).emplace_back(labels[i - 2], labels[i]);


        const string resp1 = query(pairs1);
        const string resp2 = query(pairs2);
        auto it1 = resp1.begin(), it2 = resp2.begin();

        string resp = "XX";
        for (int i = 2; i < (int) labels.size(); ++i)
            resp += ((i & 2) != 0 ? *(it1++) : *(it2++));
        return resp;
    }();


    color[0] = 0;
    color[1] = 1;
    for (int i = 2; i < (int) labels.size(); ++i)
        if (resp[i] == '1')
            color[i] = color[i - 2];
        else {
            while (color[i] == color[i - 1] || color[i] == color[i - 2])
                ++color[i];
        }

    vector<int> res[3];
    for (int i = 0; i < (int) labels.size(); ++i) {
        const int bound = i == (int) labels.size() - 1 ? n + 1 : labels[i + 1];
        for (int x = labels[i]; x < bound; ++x)
            res[color[i]].push_back(x);
    }

    cout << "A";
    for (const vector<int> &v:  res)
        cout << " " << v.size();
    cout << "\n";

    for (const vector<int> &v:  res) {
        for (const int x : v)
            cout << x << ' ';
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int T;
    cin >> T;
    while (T--) f();
    return 0;
}