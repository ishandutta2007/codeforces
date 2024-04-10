#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;
const int MAX_N = 10005;

int deg[MAX_N];


int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; ++ i) {
        int a, b;
        cin >> a >> b;
        ++ deg[a];
        ++ deg[b];
    }
    int answer = 0;
    for (int i = 1; i <= n; ++ i) {
        answer += deg[i] * (deg[i] - 1) / 2;
    }
    cout << answer << "\n";
    return 0;
}