#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

string s[] = {"+------------------------+",
                "|#.#.#.#.#.#.#.#.#.#.#.|D|)",
                "|#.#.#.#.#.#.#.#.#.#.#.|.|",
                "|#.......................|",
                "|#.#.#.#.#.#.#.#.#.#.#.|.|)",
                "+------------------------+"};

void add() {
    for (int i = 0; ; ++i)
        for (int j = 0; j < 6; ++j)
            if (s[j].length() > i && s[j][i] == '#'){
                s[j][i] = 'O';
                return;
            }
}

int main() {
#ifdef TURTLE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);

    int k;
    cin >> k;
    while (k > 0) {
        --k;
        add();
    }

    for (int i = 0; i < 6; ++i)
        cout << s[i] << "\n";



    return 0;
}