#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool sr(int a, int b) {
    return (a < b);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector <int> v(n);
    priority_queue <pair <int, int> > q;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v[i] = a;
        q.push({a, i});
    }
    int s = 0;
    vector <int> a;
    for (int i = 0; i < k; i++) {
        a.push_back(q.top().second);
        s += q.top().first;
        q.pop();
    }
    cout << s << endl;
    a.push_back(-1);
    sort(a.begin(), a.end());
    /*for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
    cout << endl;*/
    for (int i = 0; i < a.size() - 2; i++) {
        cout << a[i + 1] - a[i]<< " ";
    }
    cout << n - a[k - 1] - 1;
    return 0;
}