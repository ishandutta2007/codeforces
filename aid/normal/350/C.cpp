#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

bool cmp(Point p1, Point p2) {
    return abs(p1.x) + abs(p1.y) < abs(p2.x) + abs(p2.y);
}

void destroy(Point p, vector< pair<int, pair<int, char> > > &ans) {
    if(p.x > 0)
        ans.push_back(make_pair(1, make_pair(p.x, 'R')));
    else if(p.x < 0)
        ans.push_back(make_pair(1, make_pair(-p.x, 'L')));
    if(p.y > 0)
        ans.push_back(make_pair(1, make_pair(p.y, 'U')));
    else if(p.y < 0)
        ans.push_back(make_pair(1, make_pair(-p.y, 'D')));
    ans.push_back(make_pair(2, make_pair(0, 0)));
    if(p.y > 0)
        ans.push_back(make_pair(1, make_pair(p.y, 'D')));
    else if(p.y < 0)
        ans.push_back(make_pair(1, make_pair(-p.y, 'U')));
    if(p.x > 0)
        ans.push_back(make_pair(1, make_pair(p.x, 'L')));
    else if(p.x < 0)
        ans.push_back(make_pair(1, make_pair(-p.x, 'R')));
    ans.push_back(make_pair(3, make_pair(0, 0)));
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<Point> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i].x >> v[i].y;
    sort(v.begin(), v.end(), &cmp);
    vector< pair<int, pair<int, char> > > ans;
    for(int i = 0; i < n; i++) {
        destroy(v[i], ans);
    }
    cout << ans.size() << '\n';
    for(size_t i = 0; i < ans.size(); i++)
        if(ans[i].first == 1)
            cout << ans[i].first << ' ' << ans[i].second.first << ' '
                 << ans[i].second.second << '\n';
        else
            cout << ans[i].first << '\n';
}