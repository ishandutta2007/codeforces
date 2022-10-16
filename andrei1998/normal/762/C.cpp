#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N, M;
string A;
string B;

const int NMAX = 100000 + 5;

vector <pair <int, int> > v;

int search(int r1, int r2) {
    int st = 0;
    int dr = v.size() - 1;
    int ans = -1;

    while (st <= dr) {
        int mid = (st + dr) >> 1;
        if (v[mid].first <= r1 && v[mid].second <= r2) {
            ans = mid;
            st = mid + 1;
        }
        else
            dr = mid - 1;
    }

    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> A;
    cin >> B;

    N = A.size();
    M = B.size();
    A = " " + A;
    B = " " + B;

    int pos = 0;
    for (int i = 1; i <= M; ++ i) {
        while (pos <= N && A[pos] != B[i])
            ++ pos;

        if (pos > N)
            break;

        v.push_back({pos, i});
        pos ++;
    }

    int lMax = 0;
    int l, r;

    pos = N + 1;
    A += 'X';
    B += 'X';

    for (int i = M + 1; i; -- i) {
        while (pos && A[pos] != B[i])
            -- pos;

        if (!pos)
            break;

        int capat = search(pos - 1, i - 1) + 1;

        int cnt = M - i + 1 + capat;
        if (cnt > lMax) {
            lMax = cnt;
            l = capat;
            r = i;
        }

        pos --;
    }

    if (!lMax)
        cout << "-\n";
    else {
        for (int i = 1; i <= l; ++ i)
            cout << B[i];
        for (int i = r; i <= M; ++ i)
            cout << B[i];
        cout << '\n';
    }

    return 0;
}