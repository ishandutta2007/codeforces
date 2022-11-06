#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

char s[55][55];
int cs[4];
string al = "abcd";

void f(int x, int y, char z) {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
            s[i + x][j + y] = z;
            if (i % 2 == 1 && j % 2 == 1) {
                for (int t = 0; t < 4; t++) {
                    if (al[t] != z && cs[t] > 0) {
                        s[i + x][j + y] = al[t];
                        cs[t]--;
                        break;
                    }
                }
            }
        }
    }
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    for (int t = 0; t < 4; t++) {
        cin >> cs[t];
        --cs[t];
    }

    f(0, 0, 'a');
    f(0, 25, 'b');
    f(25, 0, 'c');
    f(25, 25, 'd');

    cout << "50 50\n";
    for (int i = 0; i < 50; i++) {
        puts(s[i]);
    }

    return 0;
}//nrlack