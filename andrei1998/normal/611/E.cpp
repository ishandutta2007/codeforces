#include <bits/stdc++.h>

#define lint long long int
#define lsb(x) ((x) & (-(x)))
using namespace std;

const int INF = 1e9 + 15;
const int mod = 1000000007;

int v[200005];

multiset <int> Set;

int biggest() {
    if (Set.empty())
        return -1;
    multiset <int> :: iterator it = Set.end();
    -- it;

    return (*it);
}

void erase_biggest() {
    multiset <int> :: iterator it = Set.end();
    -- it;

    Set.erase(it);
}

bool erase_best(int val) {
    multiset <int> :: iterator it = Set.lower_bound(val + 1);

    if (it != Set.begin()) {
        -- it;
        Set.erase(it);
        return true;
    }
    return false;
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0;
    cin >> n;

    int a, b, c;
    cin >> a >> b >> c;

    if (a > b)
        swap(a, b);
    if (a > c)
        swap(a, c);
    if (b > c)
        swap(b, c);
    if (a > b)
        swap(a, b);
    if (a > c)
        swap(a, c);
    if (b > c)
        swap(b, c);

    for (int i = 1; i <= n; ++ i)
        cin >> v[i];
    sort(v + 1, v + n + 1);

    int ans = 0;
    while (n)
        if (v[n] > a + b + c) {
            ans = -1;
            break;
        }
        else if (v[n] > b + c) {
            ++ ans;
            -- n;
        }
        else
            break;

    if (ans == -1) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 1; i <= n; ++ i)
        Set.insert(v[i]);

    //Pana cand c nu poate lua pe nimeni e clar, scoatem noi cat putem
    int top;
    while (1) {
        top = biggest();
        if (c >= top) //Iesim din faza asta
            break;

        erase_biggest();
        if (a + b >= top)
            erase_best(c);
        else if (a + c >= top)
            erase_best(b);
        else if (b + c >= top)
            erase_best(a);
        ++ ans; //Am facut ceva
    }

    //Acum c poate sterge orice, asa ca o sa-l facem sa stearga pe rand
    while (1) {
        top = biggest();
        if (top == -1)
            break;

        erase_biggest();
        if (erase_best(b))
            erase_best(a);
        else
            erase_best(a + b);

        ++ ans;
    }

    cout << ans << '\n';
    return 0;
}