#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int n;


main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n;
    int sum = 0;
    int sumin = 0;
    multiset<ii> in;
    multiset<ii> out;
    int nl = 0;
    int nlin = 0;
    while (n--) {
        int type, d;
        cin >> type >> d;
        if (type == 0) {
            if (d > 0) {
                out.insert({d, 0});
                sum += d;
            } else {
                d = -d;
                auto it = out.find({d, 0});
                if (it == out.end()) {
                    it = in.find({d, 0});
                    in.erase(it);
                    sumin -= d;
                } else out.erase(it);
                sum -= d;
            }
            if (nl > in.size()) {
                auto it = out.end();
                it--;
                auto val = *it;
                out.erase(it);
                in.insert(val);
                nlin += val.y;
                sumin += val.x;
            }
            if (!in.empty() && !out.empty()) {
                auto valin = *(in.begin());
                auto it = out.end();
                it--;
                auto valout = *it;
                if (valin < valout) {
                    auto itt = in.find(valin);
                    in.erase(itt);
                    out.insert(valin);
                    itt = out.find(valout);
                    out.erase(itt);
                    in.insert(valout);
                    nlin += valout.y;
                    sumin += valout.x;
                    nlin -= valin.y;
                    sumin -= valin.x;
                }
            }
            int ans = sum + sumin;
            if (nlin == in.size() && in.size() != 0) {
                ans -= (*in.begin()).x;
                if (!out.empty()) {
                    auto it = out.end();
                    it--;
                    ans += it->x;
                }
            }
            cout << ans << '\n';
        } else {
            if (d > 0) {
                out.insert({d, 1});
                sum += d;
                nl += 1;
            } else {
                d = -d;
                nl--;
                sum -= d;
                auto it = out.find({d, 1});
                if (it == out.end()) {
                    it = in.find({d, 1});
                    in.erase(it);
                    sumin -= d;
                    nlin--;
                } else out.erase(it);
            }
            if (nl > in.size()) {
                auto it = out.end();
                it--;
                auto val = *it;
                out.erase(it);
                in.insert(val);
                nlin += val.y;
                sumin += val.x;
            }
            if (nl < in.size()) {
                auto it = in.begin();
                auto val = *(in.begin());
                in.erase(it);
                out.insert(val);
                sumin -= val.x;
                nlin -= val.y;
            }
            if (!in.empty() && !out.empty()) {
                auto valin = *(in.begin());
                auto it = out.end();
                it--;
                auto valout = *it;
                if (valin < valout) {
                    auto itt = in.find(valin);
                    in.erase(itt);
                    out.insert(valin);
                    itt = out.find(valout);
                    out.erase(itt);
                    in.insert(valout);
                    nlin += valout.y;
                    sumin += valout.x;
                    nlin -= valin.y;
                    sumin -= valin.x;
                }
            }
            int ans = sum + sumin;
            if (nlin == in.size() && nlin != 0) {
                ans -= (*in.begin()).x;
                if (!out.empty()) {    
                    auto it = out.end();
                    it--;
                    ans += it->x;
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}