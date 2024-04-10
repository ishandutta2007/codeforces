#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define read(a) scanf("%d", &a)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 4e5;
const int INF = 2e9 + 1;

struct tmp {
    int x, num;
    bool operator != (const tmp a) const {
        return x != a.x || num != a.num;
    }
};

vector <tmp> a, b, c;

bool cmp(tmp a, tmp b) {
    return a.x < b.x || a.x == b.x && a.num < b.num;
}

bool eq(vector <tmp> a, vector <tmp> b) {
    if (a.size() != b.size())
        return false;
    fr(i, a.size())
        if (a[i] != b[i])
            return false;
    return true;
}

map <int, int> m;

int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    fr(i, n) {
        cin >> a[i].x;
        a[i].num = c[i].num = b[i].num = i;
        b[i].x = c[i].x = a[i].x;
        //m[a[i].x]++;
    }

    sort(b.begin(), b.end(), cmp);
    sort(a.begin(), a.end(), cmp);
    sort(c.begin(), c.end(), cmp);

//    for (auto it = m.begin(); it != m.end(); it++)
//    if (it->second == 1) {
//        cout << "NO";
//        return 0;
//    }

    int st = 0, cur = 0, cnt = 0;
    frab(i, 1, n) {
        if (a[i].x == a[i - 1].x)
            cur++;
        else {
            if (cur != st && !cnt) {
                rotate(a.begin() + st, a.begin() + st + 1, a.begin() + cur + 1);
                cnt++;
            }
            st = cur = i;
        }
    }
    if (cur != st && !cnt)
            rotate(a.begin() + st, a.begin() + st + 1, a.begin() + cur + 1);

    st = n - 1, cur = n - 1, cnt = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (b[i].x == b[i + 1].x)
            cur--;
        else {
            if (st - cur == 1 && !cnt)
                rotate(b.begin() + cur, b.begin() + cur + 1, b.begin() + st + 1), cnt++;
            else if (st != cur && !cnt)
                rotate(b.begin() + cur, b.begin() + cur + 2, b.begin() + st + 1), cnt++;
            st = cur = i;
        }
    }
    if (st - cur == 1 && !cnt)
        rotate(b.begin() + cur, b.begin() + cur + 1, b.begin() + st + 1);
    else if (st != cur && !cnt)
        rotate(b.begin() + cur, b.begin() + cur + 2, b.begin() + st + 1);

    if (!eq(a, b) && !eq(a, c) && !eq(b, c)) {
        cout << "YES" << endl;
        fr(i, n)
            cout << c[i].num + 1 << " ";cout << endl;
        fr(i, n)
            cout << b[i].num + 1 << " ";cout << endl;
        fr(i, n)
            cout << a[i].num + 1 << " ";cout << endl;
    }
    else
        cout << "NO";


}