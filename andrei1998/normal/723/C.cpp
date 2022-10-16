#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int NMAX = 2000 + 5;

int a[NMAX];
int b[NMAX];

map <int, int> Map;

vector <int> useless;

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        if (a[i] <= m)
            ++ b[a[i]];
    }

    int per = n / m;

    for (int i = 1; i <= n; ++ i) {
        ++ Map[a[i]];
        if (a[i] > m || Map[a[i]] > per)
            useless.push_back(i);
    }

    int ans = 0;
    for (int i = 1; i <= m; ++ i)
        if (b[i] < per)
            ans += per - b[i];


    cout << per << ' ' << ans << '\n';
    for (int i = 1; i <= m; ++ i) {
        while (b[i] < per) {
            ++ b[i];
            a[useless.back()] = i;
            useless.pop_back();
        }
    }

    for (int i = 1; i <= n; ++ i)
        cout << a[i] << " \n"[i == n];
    return 0;
}