#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 300ll;
const ll MOD = 1000000007ll;
const ll P = 259ll;

ll a[N];
ll b[N];
bool an[N];
bool am[N];
vector <int> np;

main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    cout << (n * n + 1) / 2 << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            if (!((i + j) % 2))
                cout << "C";
            else
                cout << ".";cout << endl;}
}