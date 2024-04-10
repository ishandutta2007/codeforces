#include <bits/stdc++.h>

using namespace std;

int a[200];
vector <int> v;

int main() {
	ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] == 1)
            v.push_back(i);
    }
    if (v.size() == 0){
        cout << 0 << endl;
        return 0;
    }
    if (v.size() == 1){
        cout << 1 << endl;
        return 0;
    }
    long long k = 1;
    for (int i = 1; i < v.size(); i++)
        k *= v[i] - v[i - 1];

    cout << k << endl;
}