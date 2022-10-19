#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
const int N = 500000 + 5;

int n, cnt1[N], cnt2[N];
string s;

int main(){
    //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("a.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        cin >> s;
        //checktrai
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '(') cnt++;
            else cnt--;
            if (cnt < 0) break;
        }
        if (cnt >= 0) cnt1[cnt]++;
        //checkphai
        cnt = 0;
        for (int j = s.size() - 1; j >= 0; j--) {
            if (s[j] == ')') cnt++;
            else cnt--;
            if (cnt < 0) break;
        }
        if (cnt >= 0) cnt2[cnt]++;
    }
    int res = 0;
    for (int i = 1; i <= N - 1; i++) {
        res += min(cnt1[i], cnt2[i]);
    }
    res += cnt1[0] / 2;
    cout << res;
    return 0;
}