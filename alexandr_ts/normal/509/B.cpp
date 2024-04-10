#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct tn
{
    int t;
    int num;
};

tn a[100000];

bool cmp(tn a, tn b)
{
    return a.t < b.t;
}

bool cmp2(tn a, tn b)
{
    return a.num < b.num;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i].t; a[i].num = i;}
    sort(a, a + n, cmp);
    if (a[n - 1].t - a[0].t > k)
    {
        cout << "NO";
        return 0;
    }

    vector <int> ans[n];
    cout << "YES" << endl;
    int cur = 1;
    while (a[n - 1].t > a[0].t)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i].t == a[n - 1].t)
            {
                a[i].t--;
                ans[a[i].num].push_back(cur);
            }
        }
        cur++;
    }
    int qua = a[0].t;
    for (int i = 0; i < qua; i++)
        for (int j = 0; j < n; j++)
            ans[j].push_back(1);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < (int)ans[i].size(); j++)
            cout << ans[i][j] << " ";cout << endl;}


}