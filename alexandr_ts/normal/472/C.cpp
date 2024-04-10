#include <bits/stdc++.h>

#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 100001ll;
const ll MOD = 1000000007ll;

struct pers
{
    string n1;
    string n2;
    int num;
};

pers a[N];

bool cmp(pers a, pers b)
{
    return a.num < b.num;
}

main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i< n; i++)
        cin >> a[i].n1 >> a[i].n2;
    for (int i = 0; i< n; i++)
    {
        int tmp;
        cin >> tmp;
        a[tmp - 1].num = i;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
        if (a[i].n1 > a[i].n2)
            swap(a[i].n1, a[i].n2);
    string cur = a[0].n1;
    for (int i = 1; i < n; i++)
    {
        if (a[i].n1 > cur)
            cur = a[i].n1;
        else if (a[i].n2 > cur)
            cur = a[i].n2;
        else
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

}