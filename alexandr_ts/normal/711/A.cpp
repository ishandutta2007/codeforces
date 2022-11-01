#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 5e3;
const int M = 1e3 + 10;
const int INF = 2e9 + 1;
const ld EPS = 1e-10;
const ld PI = acos(-1);

string s[N];

int main(){
	//freopen("bacon.in", "r", stdin);
	//freopen("bacon.out", "w", stdout);
    int n;
    cin >> n;
    fr(i, n)
        cin >> s[i];
    bool ans = false;
    fr(i, n)
        if (s[i][0] == 'O' && s[i][1] == 'O') {
            ans = true;
            s[i][0] = s[i][1] = '+';
            break;
        }
        else if (s[i][3] == 'O' && s[i][4] == 'O') {
            ans = true;
            s[i][3] = s[i][4] = '+';
            break;
        }
    if (!ans)
        cout << "NO";
    else {
        cout << "YES" << endl;
        fr(i, n)
            cout << s[i] << endl;
    }
}