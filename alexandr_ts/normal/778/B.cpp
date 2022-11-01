#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

int n, m;

int And[] = {
    0, 0, 0, 0,
    0, 1, 2, 3,
    0, 2, 2, 0,
    0, 3, 0, 3
};

int Or[] = {
    0, 1, 2, 3,
    1, 1, 1, 1,
    2, 1, 2, 1,
    3, 1, 1, 3
};

int Xor[] = {
    0, 1, 2, 3,
    1, 0, 3, 2,
    2, 3, 0, 1,
    3, 2, 1, 0
};

unordered_map <string, string> um;

string f(string op, string s1, string s2) {
    string ans;
    if (s1 == "?") {
        s1[0] = '2';
        fr(i, m - 1) s1 += "2";
    }
    else
        s1 = um[s1];
    if (s2 == "?") {
        s2[0] = '2';
        fr(i, m - 1) s2 += "2";
    }
    else
        s2 = um[s2];

    fr(i, m) {
        int t1 = s1[i] - '0';
        int t2 = s2[i] - '0';
        if (op == "XOR")
            ans += (Xor[t1 * 4 + t2] + '0');
        else if (op == "AND")
            ans += (And[t1 * 4 + t2] + '0');
        else if (op == "OR")
            ans += (Or[t1 * 4 + t2] + '0');
        else assert(1 == 0);
    }
    return ans;
}

string findMin(vector <int> c2, vector <int> c3) {
    string ans;
    fr(i, m)
        if (c2[i] < c3[i])
            ans += '1';
        else
            ans += '0';
    return ans;
}

string findMax(vector <int> c2, vector <int> c3) {
    string ans;
    fr(i, m)
        if (c2[i] <= c3[i])
            ans += '0';
        else
            ans += '1';
    return ans;
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    cin.ignore();
    fr(i, n) {
        string s, s1, t;
        getline(cin, s1);
        int cur = 0;
        while (s1[cur] != ' ')
            s += s1[cur++];
        cur += 4;
        t = s1.substr(cur, s1.size() - cur);
        vector <int> spaces;
        fr(j, t.size())
            if (t[j] == ' ')
                spaces.pb(j);
        if (spaces.size() == 0)
            um[s] = t;
        else {
            assert(spaces.size() == 2);
            string op = t.substr(1 + spaces[0], spaces[1] - spaces[0] - 1);
            um[s] = f(op, t.substr(0, spaces[0]), t.substr(spaces[1] + 1, (int)t.size() - spaces[1] - 1));
        }
    }

    vector <int> cnt2(m, 0);
    vector <int> cnt3(m, 0);
    for (auto it: um) {
        fr(i, it.second.size())
            if (it.second[i]== '2')
                cnt2[i]++;
            else if (it.second[i] == '3')
                cnt3[i]++;
    }
    cout << findMin(cnt2, cnt3) << endl << findMax(cnt2, cnt3) << endl;
}