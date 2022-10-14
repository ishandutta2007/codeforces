#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> cnt(101);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int k = 0;
    int more_than_twice = 0;
    for (int i = 0; i < 101; i++) {
        if (cnt[i] == 1) {
            k++;
        }
        if (cnt[i] > 2) {
            more_than_twice++;
        }
    }
    if (k % 2 == 1 && more_than_twice == 0) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << "\n";
    if (k % 2 == 0) {
        bool f = false;
        for (int i = 0; i < n; i++) {
            if (cnt[a[i]] == 1) {
                if (f == false) {
                    cout << 'A';
                }
                else {
                    cout << 'B';
                }
                f = !f;
            }
            else {
                cout << 'A';
            }
        }
        return 0;
    }
    bool f = false;
    bool use = false;
    for (int i = 0; i < n; i++) {
        if (cnt[a[i]] == 1) {
            if (f == false) {
                cout << 'A';
            }
            else {
                cout << 'B';
            }
            f = !f;
            continue;
        }
        if (cnt[a[i]] > 2 && use == false) {
            use = true;
            cout << 'B';
            continue;
        }
        cout << 'A';
    }
	return 0;
}