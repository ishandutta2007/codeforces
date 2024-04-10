#include <bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int cnt_a = 0, cnt_b = 0, ok = 0;
    for (int i = 0; i < n; ++i) {
        if (s1[i] == 'a') cnt_a++, ok++;
        else cnt_b++;
        if (s2[i] == 'a') cnt_a++;
        else cnt_b++;
    }
    if (cnt_a % 2 == 1 || cnt_b % 2 == 1) {
        cout << -1 << '\n';
        return 0;
    }
    vector < int > ab, ba;
    for (int i = 0; i < n; ++i) {
        if (s1[i] == 'a' && s2[i] == 'b') ab.push_back(i);
        if (s1[i] == 'b' && s2[i] == 'a') ba.push_back(i);
    }
    vector < pair < int, int > > out;
    if (ok <= cnt_a / 2) {
        int ptr = 0;
        for (int i = 0; i < (cnt_a / 2 - ok); ++i) {
            out.push_back({ba[ptr], ba[ptr + 1]});
            ptr += 2;
        }
        for (int i = 0; i < (int)ab.size() - 1; i += 2) {
            out.push_back({ab[i], ab[i + 1]});
        }
        for (int i = ptr; i < (int)ba.size() - 1; i += 2) {
            out.push_back({ba[i], ba[i + 1]});
        }
        if ((int)ab.size() % 2 == 1) out.push_back({ab.back(), ab.back()}), out.push_back({ab.back(), ba.back()});
    }
    else {
        swap(cnt_a, ok);
        swap(ab, ba);
        int ptr = 0;
        for (int i = 0; i < (cnt_a / 2 - ok); ++i) {
            out.push_back({ba[ptr], ba[ptr + 1]});
            ptr += 2;
        }
        for (int i = 0; i < (int)ab.size() - 1; i += 2) {
            out.push_back({ab[i], ab[i + 1]});
        }
        for (int i = ptr; i < (int)ba.size() - 1; i += 2) {
            out.push_back({ba[i], ba[i + 1]});
        }
        if ((int)ab.size() % 2 == 1) out.push_back({ab.back(), ab.back()}), out.push_back({ab.back(), ba.back()});
    }
    cout << out.size() << '\n';
    for (auto key : out) cout << key.first + 1 << " " << key.second + 1 << '\n';
    return 0;
}