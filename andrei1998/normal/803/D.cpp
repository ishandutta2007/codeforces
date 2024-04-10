#include <iostream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

int K;
vector <string> tokens;

bool works(int w) {
    int cnt = 0;
    int rem = 0;

    for (auto it: tokens) {
        if (it.size() > rem) {
            ++ cnt;
            rem = w;
            if (cnt > K)
                return false;
        }

        rem -= it.size();
    }

    return cnt <= K;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> K; cin.ignore();
    string str;
    getline(cin, str);

    bool nw = true;
    for (auto it: str)
        if (isalpha(it)) {
            if (nw) {
                tokens.push_back(string());
                nw = false;
            }
            tokens.back() += it;
        }
        else {
            tokens.back() += it;
            nw = true;
        }

    int st = -1;
    for (auto &it: tokens)
        st = max(st, (int)it.size());
    int dr = str.size() - 1;
    int ans = str.size();

    while (st <= dr) {
        int mid = (st + dr) >> 1;
        if (works(mid)) {
            ans = mid;
            dr = mid - 1;
        }
        else
            st = mid + 1;
    }

    cout << ans << '\n';
    return 0;
}