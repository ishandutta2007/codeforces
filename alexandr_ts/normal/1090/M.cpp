#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int N = 1e6 + 10;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    ll n, k, answer = 1;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i < n; i++)
    {
        int t = 1;
        while (i < n && a[i] != a[i - 1]){
            t++;
            i++;
        }
        //cout << t << endl;
        answer = max(answer, (ll)t);
    }
    cout << answer << endl;
}