#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 300000ll;
const ll MOD = 1000000007ll;
const ll P = 259ll;

ll a[N];
bool pr[N];

vector <int> np;

main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 2; i < sqrt(n) + 1; i++)
        if (!pr[i])
            for (int j = 2 * i; j <= n; j += i)
                pr[j] = true;
    for (int i = 1; i <= n; i++)
        if (pr[i])
            np.push_back(i);
//    for (int i = 0; i < np.size(); i++)
//        cout << np[i] << " ";cout << endl;
    for (int i = 0; i < np.size(); i++)
        if (pr[n - np[i]])
            {cout << np[i] << " " << n - np[i]; return 0;}

}