#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool gl[1000000];
ld qua[1000000];

bool cmp1(int a, int b)
{
    return a > b;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    getline(cin, s);
    ll n = s.size();
    for (ll i = 0; i < n; i++)
        if (s[i] == 'I' || s[i] == 'A' || s[i] == 'O' || s[i] == 'E' || s[i] == 'U' || s[i] == 'Y')
            gl[i] = true;

    vector <ll> que;
    ll sm = 0;
    for (ll i = 0; i < n; i++){
        sm += gl[i]; if(gl[i]) que.push_back(i), que.push_back(n - i - 1);}
    if (sm == 0)
    {
        cout << "0.00000000";
        return 0;
    }
    ll quag = sm;
    sort(que.begin(), que.end());
    ll cur = 0;
    qua[0] = sm;
    for (ll i = 1; i <= (n - 1) / 2; i++)
    {
        while (que[cur] < i)
            cur++;
        sm += quag - cur;
        qua[i] = sm;
    }
    for (ll i = n - 1; i >= n / 2; i--)
        qua[i] = qua[n - i - 1];

    ld ans = 0;
    for (ll i = 0; i < n; i++)
        ans += qua[i] / (i + 1);
    //for (int i = 0; i < n; i++)
      //  cout << qua[i] << " ";
    printf("%.10lf", (double)ans);

}