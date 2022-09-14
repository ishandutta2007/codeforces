#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>
#include <queue>

using namespace std;

struct order {
    int rectorate;
    int grey;
    int num;
};

int comOrder(order a, order b) {
    if (a.rectorate < b.rectorate || (a.rectorate == b.rectorate && a.grey > b.grey))
        return 1;
    else
        return 0;
}

int main() {
    int n, p, k;
    cin >> n >> p >> k;
    vector< order > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].grey >> a[i].rectorate;
        a[i].num = i + 1;
    }
    sort(a.begin(), a.end(), comOrder);
    priority_queue< pair<int, int> > q;
    for (int i = n - k; i < n; i++)
        q.push(make_pair(-a[i].grey, a[i].num));
    int t = n - k;
    for (int i = n - k - 1; i >= p - k; i--) {
        if (-q.top().first < a[i].grey) {
            q.pop();
            q.push(make_pair(-a[i].grey, a[i].num));
            t = i;
        }
    }
    
    for (int i = 0; i < k; i++) {
        cout << q.top().second << " ";
        q.pop();
    }
    
    for (int i = t - 1; i >= t - (p - k); i--)
        cout << a[i].num << " ";
    cout << endl;
    return 0;
}