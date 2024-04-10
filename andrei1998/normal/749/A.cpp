#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> sol;
    while (n >= 4) {
        sol.push_back(2);
        n -= 2;
    }

    sol.push_back(n);

    cout << sol.size() << '\n';
    for (int i = 0; i < sol.size(); ++ i)
        cout << sol[i] << " \n"[i + 1 == sol.size()];
    return 0;
}