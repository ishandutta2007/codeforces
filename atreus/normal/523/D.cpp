#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 500;
pair <long long, long long> p[maxn];
multiset <long long> s;
vector <long long> v;

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;
    for (int i = 0; i < k; i++)
        s.insert(0);
    for (int i = 0; i < n; i++){
        multiset<long long>::iterator it = s.begin();
        long long x = p[i].second + (max((*it), p[i].first));
        v.push_back(x);
        s.erase(it);
        s.insert(x);
    }
    for (int i = 0; i < n; i++)
        cout << v[i] << endl;
}