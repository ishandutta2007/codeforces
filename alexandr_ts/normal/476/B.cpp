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
    string s1, s2;
    cin >> s1 >> s2;
    int n = (int)s1.size();
    int qua = 0;
    for (int i = 0; i < n; i++)
        if (s1[i] == '+')
            qua++;
    int qua1 = 0;
    for (int i = 0; i < n; i++)
        if (s2[i] == '?')
            qua1++;
        else if (s2[i] == '+')
            qua--;
    if (qua < 0 || qua1 < qua)
    {
        printf("0.0000000000");
        return 0;
    }
    ll t = 1;
    for (int i = qua + 1; i <= qua1; i++)
        t *= i;
    for (int i = 1; i <= qua1 - qua; i++)
        t /= i;
    ll q = (1 << qua1);
    ld ans = (ld)t / (ld)q;
    printf("%.10lf", (double)ans);


}