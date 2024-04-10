#include <bits/stdc++.h>

using namespace std;

string S, T;

int freqT[26];

long long int freqS[26];

bool works(int cnt) {
    for (int i = 0; i < 26; ++ i)
        freqS[i] = 0;
    int cntSign = 0;
    for (auto it: S)
        if (it == '?')
            ++ cntSign;
        else
            ++ freqS[it - 'a'];
    long long int ss = 0;
    for (int i = 0; i < 26; ++ i) {
        freqS[i] -= 1LL * freqT[i] * cnt;
        if (freqS[i] < 0)
            ss -= freqS[i];
    }
    return ss <= cntSign;
}

string anss;
void build() {
    anss = S;
    for (auto &it: anss)
        if (it == '?') {
            bool done = false;
            for (int i = 0; i < 26; ++ i)
                if (freqS[i] < 0) {
                    freqS[i] ++;
                    it = (char)('a' + i);
                    done = true;
                    break;
                }
            if (!done)
                it = 'a';
        }
}

int main() {
    cin >> S >> T;
    for (auto it: T)
        ++ freqT[it - 'a'];

    int ans = 0;
    int st = 1;
    int dr = S.size();

    while (st <= dr) {
        int mid = (st + dr) >> 1;
        if (works(mid)) {
            ans = mid;
            st = mid + 1;
        }
        else
            dr = mid - 1;
    }

    works(ans);
    build();
    cout << anss << '\n';
    return 0;
}