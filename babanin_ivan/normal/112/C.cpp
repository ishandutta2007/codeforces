#include <iostream>
#include <string>
using namespace std;

string s1, s2;
bool b = false;

int main () {
    //freopen ("input.txt", "rt", stdin);
    //freopen ("output.txt", "wt", stdout);
    long long n, x, y;

    cin >> n >> x >> y;
    if (y < n) {
        printf("-1\n");
        return 0;
    }
    if ((n - 1 + (y - n + 1) * (y - n + 1)) >= x) {
        for (int i = 0; i < n - 1; ++i)
            printf("1\n");
        cout << y - (n - 1) << endl;
        return 0;
    }
    printf("-1\n");
}