#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) x.begin(), x.end()

const int INF = 1e9;

int main() {
    long long a, b;
    cin >> a >> b;
    long long next = 0;
    int start = 0;
    vector <int> f;
    for (int i = 1; ; i++) {
        if (a - i >= 0) {
            f.push_back(i);
            a -= i;
            if (a == 0) {
                start = i + 1;
                break;
            }
            continue;
        }
        if (a - i < 0) {
            if (i - a < i) {
                f.erase(f.begin() + i - a - 1);
                f.push_back(i);
                start = i + 1;
                next = i - a;
                break;
            }
            else {
                start = i;
                break;
            }
        }
    }
    if (next > b) {
        cout << f.size() << "\n";
        for (auto c : f) {
            cout << c << " ";
        }
        cout << "\n";
        cout << 0;
        return 0;
    }
    vector <int> s;
    if (next != 0) {
        s.push_back(next);
    }
    b -= next;
    int ans2 = 0;
    for (int i = start; ; i++) {
        if (b - i < 0) {
            break;
        }
        else {
            s.push_back(i);
            b -= i;
        }
    }
    cout << f.size() << "\n";
    for (auto c : f) {
        cout << c << " ";
    }
    cout << "\n";
    cout << s.size() << "\n";
    for (auto c : s) {
        cout << c << " ";
    }
	return 0;
}