#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = 2009;
string a[MxN + 9];
bool dp[MxN + 9][MxN + 9];
int choice[MxN + 9][MxN + 9];

bool canTurn(const string &s1, const string &s2) {
    assert(s1.size() == 7);
    assert(s2.size() == 7);
    for(int i = 0; i < 7; ++i)
    if(s1[i] == '1' && s2[i] == '0')
        return false;
    return true;
}

int diff1(const string &s1, const string &s2) {
    return count(s2.begin(), s2.end(), '1') - count(s1.begin(),s1.end(), '1');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    const vector<string> encodings = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    assert(encodings.size() == 10);


    int n, K;
    cin >> n >> K;
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    for(int i = n; i >= 0; --i)
        for(int k = 0; k <= K; ++k) {
            bool &res = dp[i][k] = false;
            int &ch = choice[i][k];
            if(i == n) {
                res = !k;
                continue;
            }
            for(int d = 9; d >= 0; --d) {
                if(!canTurn(a[i], encodings[d]))
                continue;
                const int cnt1 = diff1(a[i], encodings[d]);
                if(cnt1 <= k && dp[i+1][k - cnt1])
                {
                    res = true;
                    ch = d;
                    break;
                }
            }
        }

    if(!dp[0][K]) {
        cout << -1;
        return 0;
    }
    for(int i = 0; i < n; ++i) {
        const int d = choice[i][K];
        cout << d ;
        K -= diff1(a[i], encodings[d]);

    }
    return 0;
}