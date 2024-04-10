#include <bits/stdc++.h>

#define lint long long int
#define lsb(x) ((x) & (-(x)))
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf (1 << 30)
using namespace std;

int f(int x) {
    return x / 10;
}

int s(int x) {
    return x % 10;
}

bool taxi (int a, int b, int c) {
    return (a == b && b == c && f(a) == s(a));
}

bool pizza (int a, int b, int c) {
    return (f(a) > s(a) && s(a) > f(b) && f(b) > s(b) && s(b) > f(c) && f(c) > s(c));
}

string names[105];

int taxis[105];
int pizzas[105];
int girls[105];

int main()
{
    int n = 0;
    cin >> n;

    int sz, a, b, c;
    char pp;

    for (int i = 1; i <= n; i++) {
        cin >> sz >> names[i];

        while (sz--) {
            cin >> a >> pp;
            cin >> b >> pp;
            cin >> c;

            if (taxi(a, b, c))
                taxis[i] ++;
            else if (pizza(a, b, c))
                pizzas[i] ++;
            else
                girls[i] ++;
        }
    }

    vector <string> ans;
    int best = -1;

    for (int i = 1; i <= n; i++)
        if (taxis[i] > best) {
            ans.clear();
            best = taxis[i];
            ans.pb(names[i]);
        }
        else if (taxis[i] == best)
            ans.pb(names[i]);

    cout << "If you want to call a taxi, you should call: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ",."[i + 1 == ans.size()];

        if (i + 1 != ans.size())
            cout << ' ';
    }
    cout << endl;


    /////////////

    ans.clear();
    best = -1;

    for (int i = 1; i <= n; i++)
        if (pizzas[i] > best) {
            ans.clear();
            best = pizzas[i];
            ans.pb(names[i]);
        }
        else if (pizzas[i] == best)
            ans.pb(names[i]);

    cout << "If you want to order a pizza, you should call: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ",."[i + 1 == ans.size()];

        if (i + 1 != ans.size())
            cout << ' ';
    }
    cout << endl;


    /////////////

    ans.clear();
    best = -1;

    for (int i = 1; i <= n; i++)
        if (girls[i] > best) {
            ans.clear();
            best = girls[i];
            ans.pb(names[i]);
        }
        else if (girls[i] == best)
            ans.pb(names[i]);

    cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ",."[i + 1 == ans.size()];

        if (i + 1 != ans.size())
            cout << ' ';
    }
    cout << endl;


    return 0;
}