#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 150 * 1000 + 5;
int t[MAXN];
char bad[MAXN];
vector<int> vbad;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> t[i];
    int cnt = 0;
    for(int i = 0; i < n; i++)
        if(i & 1) {
            if((i && t[i] <= t[i - 1]) || (i + 1 < n && t[i] <= t[i + 1])) {
                bad[i] = true;
                vbad.push_back(i);
                cnt++;
            }
        }
        else {
            if((i && t[i] >= t[i - 1]) || (i + 1 < n && t[i] >= t[i + 1])) {
                bad[i] = true;
                vbad.push_back(i);
                cnt++;
            }
        }
    if(cnt > 10) {
        cout << 0 << '\n';
        return 0;
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        if(bad[i]) {
            for(int j = 0; j < n; j++) {
                if(bad[j] && j <= i)
                    continue;
                vbad.push_back(j);
                swap(t[i], t[j]);
                bool ok = true;
                for(size_t k = 0; k < vbad.size(); k++) {
                    int ii = vbad[k];
                    if(ii & 1) {
                        if((ii && t[ii] <= t[ii - 1]) ||
                           (ii + 1 < n && t[ii] <= t[ii + 1]))
                            ok = false;
                    }
                    else {
                        if((ii && t[ii] >= t[ii - 1]) ||
                           (ii + 1 < n && t[ii] >= t[ii + 1]))
                            ok = false;
                    }
                }
                if(ok)
                    ans++;
                vbad.pop_back();
                swap(t[i], t[j]);
            }
        }
    cout << ans << '\n';
    return 0;
}