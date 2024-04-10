#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
};

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

int cnt[16];


string back[6] = {"S", "M", "L", "XL", "XXL", "XXXL"};
int ans[111111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    for (int i = 0; i < 6; i++) {
        sci(cnt[i]);
    }

    unordered_map<string, int> num;
    num["S"] = 0;
    num["M"] = 1;
    num["L"] = 2;
    num["XL"] = 3;
    num["XXL"] = 4;
    num["XXXL"] = 5;

    scid(n);

    vector<pair<int, int> > a;

    for (int i = 0; i < n; i++) {
        scids(s);
        int x = s.find(",");
        if (x < 0) {
            int t = num[s];
            if (cnt[t] == 0) {
                cout << "NO";
                return 0;
            }
            cnt[t]--;
            ans[i] = t;
            continue;
        }
        string s1 = s.substr(0, x);
//        cerr << s1 << endl;
        a.push_back({num[s1], i});
    }

    sort(a.begin(), a.end());

    for (auto& i : a) {
        if (cnt[i.first] != 0) {
            cnt[i.first]--;
            ans[i.second] = i.first;
        } else if (cnt[i.first + 1] != 0) {
            cnt[i.first + 1]--;
            ans[i.second] = i.first + 1;
        } else {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << back[ans[i]] << "\n";
    }


    return 0;
}