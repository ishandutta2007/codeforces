#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

map <int, int> xha, yha;
map <pair <int, int>, int> yox;

int main() {
    ios_base::sync_with_stdio(false);
    long long n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        ans += (xha[a] ++) + (yha[b] ++) - (yox[make_pair(a, b)] ++);
    }
    cout << ans << endl;
}