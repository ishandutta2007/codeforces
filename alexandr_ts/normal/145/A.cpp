#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 1e3 + 1;
const ld EPS = 1e-8;

int a[N];
vector <int> ans[N];
int used[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    string s, t;
    cin >> s >> t;
    int s4 = 0, s7 = 0, t4 = 0, t7 = 0;
    fr(i, s.size())
        if (s[i] == '4') s4++;
        else s7++;
    fr(i, t.size())
        if (t[i] == '4') t4++;
        else t7++;
    int dif4 = 0, dif7 = 0;
    fr(i, s.size())
        if (s[i] != t[i])
            if (s[i] == '4')
                dif4++;
            else
                dif7++;
    cout << abs(dif4 - dif7) + min(dif4, dif7);

}