#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 55

int n, k, i;
string s;

int ans[maxN];
vector<string> name;

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> k;
    for (i = 1; i < k; i++)  ans[i] = i;
    for (i = k; i <= n; i++) {
        cin >> s;
        if (s == "YES") {
            ans[i] = i;
        } else {
            ans[i] = ans[i - k + 1];
        }
    }

    for (char c1 = 'A'; c1 <= 'Z'; c1++) {
        for (char c2 = 'a'; c2 <= 'z'; c2++) {
            string aux = "";
            aux += c1;
            aux += c2;
            name.pb(aux);
        }
    }

    for (i = 1; i <= n; i++)
        cout << name[ans[i]] << ' ';


    return 0;
}