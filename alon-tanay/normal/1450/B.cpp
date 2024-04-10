#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int t, n;
    long int k, x, y, add_max, add_min, sub_max, sub_min, add, sub;
    vector<long int> points;
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t;
    for(int i = 0; i < t; i ++) {
        points.clear();
        bool found = false;
        cin >> n >> k;
        cin >> x >> y;
        add_max = x+y;
        sub_max = x-y;
        add_min = add_max;
        sub_min = sub_max;
        points.push_back(x);
        points.push_back(y);
        for(int j = 1; j < n; j ++) {
            cin >> x >> y;
            add_max = max(add_max, x+y);
            add_min = min(add_min, x+y);
            sub_max = max(sub_max, x-y);
            sub_min = min(sub_min, x-y);
            points.push_back(x);
            points.push_back(y);
        }
        if(add_max-2*k > add_min || sub_max-2*k > sub_min) {
            cout << "-1" << endl;
            continue;
        }
        for(int j = 0; j < n*2; j += 2) { 
            add = points[j]+points[j+1];
            sub = points[j]-points[j+1];
            if(add >= add_max - k && add <= add_min + k && sub >= sub_max - k && sub <= sub_min + k) {
                found = true;
                break;
            }
        }
        cout << (found ? "1" : "-1") << endl;
    }
    return 0;
}