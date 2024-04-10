#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 400;
int a[maxn];
pair <int, int> p[maxn];
vector <int> v;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s[0] == '1')
        a[0] = 1;
    else
        a[0] = -1;
    p[0] = make_pair(a[0], 0);
    for (int i = 1; i < n; i++){
        p[i] = make_pair(a[i - 1] + (((s[i] - '0') * 2) - 1), i);
        a[i] = p[i].first;
    }
    sort (p, p + n);
    int k = 0;
    for (int i = 0; i < n - 1; i++){
        if (p[i].first == 0){
            k = max(p[i].second + 1, k);
            continue;
        }
        for (int j = i + 1; j < n; j++){
            if (p[i].first == p[j].first){
                k = max(k, p[j].second - p[i].second);
            }
            else {
                i = j - 1;
                break;
            }
        }
    }
    if (p[n - 1].first == 0)
        k = max(k, p[n - 1].second + 1);
    cout << k << endl;
}