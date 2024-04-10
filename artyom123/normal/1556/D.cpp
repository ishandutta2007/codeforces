 #include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long
#define mp make_pair

const long long INFLL = 1e18;
const int INF = 1e9 + 1;

bool get(int x, int j) {
    return x & (1 << j);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 3; i < n; i++) {
        cout << "and " << 1 << " " << i + 1 << endl;
        int x;
        cin >> x;
        cout << "or " << 1 << " " << i + 1 << endl;
        int y;
        cin >> y;
        a[i] = x ^ y;
    }
    vector<int> and1(3), or1(3);
    for (int i = 0; i < 3; i++) {
        cout << "and " << i + 1 << " " << (i + 1) % 3 + 1 << endl;
        cin >> and1[i];
        cout << "or " << i + 1 << " " << (i + 1) % 3 + 1 << endl;
        cin >> or1[i];
    }
    vector<int> b(n);
    for (int j = 30; j >= 0; j--) {
        for (int i = 0; i < 3; i++) {
            if (get(and1[i], j) == 1) {
                b[i] |= (1 << j);
                b[(i + 1) % 3] |= (1 << j);
                if (get(and1[(i + 1) % 3], j)) b[(i + 2) % 3] |= (1 << j);
                break;
            }
            if (get(or1[i], j) == 0) {
                if (get(or1[(i + 1) % 3], j)) b[(i + 2) % 3] |= (1 << j);
                break;
            }
        }
    }
    for (int i = 3; i < n; i++) b[i] = a[i] ^ b[0];
    sort(all(b));
    cout << "finish " << b[k - 1] << endl;
    return 0;
}