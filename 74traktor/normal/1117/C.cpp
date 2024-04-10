#include <bits/stdc++.h>

using namespace std;

#define int long long
pair < int, int > pref[100005];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.size(); ++i){
        if (i == 0){
            if (s[i] == 'U') pref[i] = {0, 1};
            else if (s[i] == 'D') pref[i] = {0, -1};
            else if (s[i] == 'L') pref[i] = {-1, 0};
            else pref[i] = {1, 0};
        }
        else{
            if (s[i] == 'U') pref[i] = {pref[i - 1].first, pref[i - 1].second + 1};
            else if (s[i] == 'D') pref[i] = {pref[i - 1].first, pref[i - 1].second - 1};
            else if (s[i] == 'L') pref[i] = {pref[i - 1].first - 1, pref[i - 1].second};
            else pref[i] = {pref[i - 1].first + 1, pref[i - 1].second};
        }
    }
    int l = -1, r = (int)1e16;
    while (r - l > 1){
        int mid = (r + l) / 2;
        int XX = pref[n - 1].first * (mid / n), YY = pref[n - 1].second * (mid / n);
        if (mid % n != 0) XX += pref[mid % n - 1].first, YY += pref[mid % n - 1].second;
        if (abs(x2 - (XX + x1)) + abs(y2 - (YY + y1)) <= mid) r = mid;
        else l = mid;
    }
    int mid = r;
    int XX = pref[n - 1].first * (mid / n), YY = pref[n - 1].second * (mid / n);
    if (mid % n != 0) XX += pref[mid % n - 1].first, YY += pref[mid % n - 1].second;
    if (abs(x2 - (XX + x1)) + abs(y2 - (YY + y1)) <= mid) cout << r << endl;
    else cout << -1 << endl;
    return 0;
}