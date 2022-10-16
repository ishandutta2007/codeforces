#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 100 * 1000 + 5;
int a[MAXN], s[2][MAXN];
vector< pair<int, int> > vec;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for(int i = 0; i < n; i++) {
        s[0][i + 1] = s[0][i];
        s[1][i + 1] = s[1][i];
        s[a[i]][i + 1]++;
    }
    for(int t = 1; t <= n; t++) {
        int i = 0, win[2] = {0, 0}, lastWin = -1;
        bool bad = false;
        while(i < n) {
            int l = i, r = n;
            while(l < r - 1) {
                int m = (l + r) / 2;
                if(s[0][m] - s[0][i] >= t || s[1][m] - s[1][i] >= t)
                    r = m;
                else
                    l = m;
            }
            if(s[0][r] - s[0][i] < t && s[1][r] - s[1][i] < t) {
                bad = true;
                break;
            }
            if(s[0][r] - s[0][i] >= t) {
                win[0]++;
                lastWin = 0;
            }
            else {
                win[1]++;
                lastWin = 1;
            }
            i = r;
        }
        if(win[0] == win[1] || (win[0] > win[1] && lastWin != 0) ||
           (win[0] < win[1] && lastWin != 1))
            bad = true;
        if(!bad)
            vec.push_back(make_pair(max(win[0], win[1]), t));
    }
    sort(vec.begin(), vec.end());
    cout << vec.size() << '\n';
    for(size_t i = 0; i < vec.size(); i++)
        cout << vec[i].first << ' ' << vec[i].second << '\n';
    return 0;
}