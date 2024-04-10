#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;

vector <int> v;

int main()
{
    ios_base :: sync_with_stdio(false);

    int n;
    cin >> n;
    cin >> str;

    int current = 1;
    for (int i = 1; i < n; ++ i) {
        if (str[i] != str[i - 1]) {
            v.push_back(current);
            current = 1;
        }
        else
            ++ current;
    }

    v.push_back(current);

    int ones = 0, twos = 0;
    int threes = 0;

    for (int i = 0; i < v.size(); ++ i)
        if (v[i] == 1)
            ones ++;
        else if (v[i] == 2)
            twos ++;
        else
            threes ++;

    int ans = v.size();
    if (twos)
        ans ++;

    if (twos >= 2 || threes >= 1)
        ans = v.size() + 2;

    cout << ans << '\n';
    return 0;
}