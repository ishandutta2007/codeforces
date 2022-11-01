#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef unsigned long long ll;

const int N = 1e6 + 10;
const int INF = 2e9;
const int ALPH = 300;

char a[N];
bool b[N];

int main() {
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    frab(i, 0, n) {
        cin >> a[i];
        if (a[i] == '*')
            b[i] = true;
    }

    fr(i1, n)
        if (b[i1])
            frab(i2, i1 + 1, n)
                if (b[i2])
                    frab(i3, i2 + 1, n)
                        if (b[i3])
                            frab(i4, i3 + 1, n)
                                if (b[i4])
                                    frab(i5, i4 + 1, n)
                                        if (b[i5])
                                            if (i5 - i4 == i4 - i3 && i5 - i4 == i3 - i2 && i5 - i4 == i2 - i1) {
                                                cout << "yes";
                                                return 0;
                                            }
    cout << "no";


}