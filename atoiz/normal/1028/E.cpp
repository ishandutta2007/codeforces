#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define PREV(i) ((i+n-1)%n)
#define NEXT(i) ((i+1)%n)

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
	long long a[n], b[n];
	for (int i = 0; i < n; ++i) cin >> b[i];

    if (n == 2) {
		if (b[0] + b[1] == 0) cout << "YES\n1 1" << endl;
        else if (b[0] == b[1]) cout << "NO" << endl;
        else if (b[0] < b[1]) {
            cout << "YES" << endl;
            cout << b[0] + b[1] << ' ' << b[1] << endl;
        } else {
            cout << "YES" << endl;
            cout << b[0] << ' ' << b[0] + b[1] << endl;
        }
        return 0;
    }

    int maxv = b[0];
    for (int i = 1; i < n; ++i) {
        if (maxv < b[i]) {
			maxv = b[i];
        }
    }
//
    bool allsame = 1;
    for (int i = 0; i < n; ++i) {
        if (b[i] != maxv) {
			allsame = 0;
			break;
        }
    }
    if (allsame) {
        if (maxv == 0) {
            cout << "YES" << endl;
            for (int i = 0; i < n; ++i) cout << "1 ";
            cout << endl;
        } else {
			cout << "NO" << endl;
        }
		return 0;
    }

    int si;
    for (int i = 0; i < n; ++i) {
        if (b[i] == maxv && b[PREV(i)] != maxv) {
            si = i;
            break;
        }
    }

    a[si] = b[si];
	if (a[si] <= b[PREV(si)]) {
		a[si] = ((long long) ceil(b[PREV(si)] / b[si]) + 2) * b[si];
	}

    do {
		for (int i = PREV(si); i != si; i = PREV(i)) {
			a[i] = b[i];
			if (a[i] <= b[PREV(i)]) {
				a[i] = ((long long) ceil(b[PREV(i)] / a[NEXT(i)]) + 1) * a[NEXT(i)] + b[i];
			}
		}
    } while (a[si] % a[NEXT(si)] != b[si]);

    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
}