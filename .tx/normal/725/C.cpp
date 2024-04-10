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

vector<int> ps[256];

string ans[2] = {"", ""};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    string s;
    sci(s);
    int n = s.length();
    for (int i = 0; i < n; i++) {
        ps[s[i]].push_back(i);
    }

    int x = -1;
    for (int i = 0; i < 256; i++) {
        if (ps[i].size() == 2) {
            x = i;
            break;
        }
    }
    int p1 = ps[x][0];
    int p2 = ps[x][1];
    if (p1 + 1 == p2) {
        cout << "Impossible";
        return 0;
    }
    int d = p2 - p1;

    if (d > 13) {
        rotate(s.begin(), s.begin() + p2, s.end());
        d = 27 - d;
        p1 = n - 1 - p2;
        p2 = 0;
        swap(p1, p2);
    }

    rotate(s.begin(), s.begin() + p1, s.end());

    for (int i = 0; i < 13 - (d + 1)/2; i++) {
        char c = s.back();
        s.pop_back();
        s = c + s;
    }


    int add = 0;
    int cp = 0;
    bool wasx = false;

    for (int i = 0; i < n; i++) {
        if (s[i] == x && wasx) {
            continue;
        }
        wasx |= s[i] == x;
        if (cp < 13) {
            ans[0] += s[(-add + i + n) % n];
        } else {
            ans[1] += s[(-add + i + n) % n];
        }
        cp++;
    }

    reverse(ans[1].begin(), ans[1].end());
    cout << ans[0] << "\n" << ans[1];


    return 0;
}