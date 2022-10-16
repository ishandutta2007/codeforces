#include <iostream>
#include <string>
#include <sstream>

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
            ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

int n;
int x[55];
int y[55];

string build (int x[55]) {
    string ans = "";
    string aux;

    for (int i = 1; i <= n; ++ i) {
        aux = "(((abs((t-" + SSTR(i) + "))-1)-abs((abs((t-" + SSTR(i) + "))-1)))*(0-" + SSTR(x[i]) + "))";

        if (i > 1) {
            ans += "+" + aux;
            ans = "(" + ans + ")";
        }
        else
            ans = aux;
    }

    return ans;
}

int main()
{
    cin >> n;

    int r;
    for (int i = 1; i <= n; ++ i) {
        cin >> x[i] >> y[i] >> r;

        for (r = x[i]; r <= x[i] + 1; ++ r)
            if (r % 2 == 0)
                break;
        x[i] = r / 2;

        for (r = y[i]; r <= y[i] + 1; ++ r)
            if (r % 2 == 0)
                break;
        y[i] = r / 2;
    }

    cout << build(x) << '\n';
    cout << build(y) << '\n';

    return 0;
}