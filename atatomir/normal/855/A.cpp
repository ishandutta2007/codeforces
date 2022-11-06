#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

int n, i;
string s;
map<string, bool> M;

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> s;
        if (M[s])
            cout << "YES\n";
        else
            cout << "NO\n";
        M[s] = true;
    }


    return 0;
}