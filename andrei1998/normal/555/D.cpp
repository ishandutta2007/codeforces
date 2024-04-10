#include <iostream>
#include <algorithm>
#include <cmath>

#define lint long long int
using namespace std;

int n, m;

struct elem {
    int val;
    int pos;
} v[200005];

lint _v[200005];

bool operator< (const elem &a, const elem &b) {
    return a.val < b.val;
}

int get_ante (int a, int l) {
    int ans = lower_bound(_v + 1, _v + n + 1, _v[a] - l) - _v;

    if (ans == a)
        return -1;
    return ans;
}

int get_next (int a, int l) {
    int ans = upper_bound(_v + 1, _v + n + 1, _v[a] + l) - _v - 1;

    if (ans == a)
        return -1;
    return ans;
}

int get_ans (int a, int l) {
    bool right = true;

    int _next;
    while (l) {
        if (right) {
            _next = get_next(a, l);

            if (_next == -1) {
                _next = get_ante(a, l);

                if (_next == -1) {
                    l = 0;
                    continue ;
                }
            }
            else
                right ^= 1;
        }
        else {
            _next = get_ante(a, l);

            if (_next == -1) {
                _next = get_next(a, l);

                if (_next == -1) {
                    l = 0;
                    continue ;
                }
            }
            else
                right ^= 1;
        }

        if (!right) {
            if (get_ante(a, l) == -1)
                l %= (2ll * abs(_v[a] - _v[_next]));
        }
        else {
            if (get_next(a, l) == -1)
                l %= (2ll * abs(_v[a] - _v[_next]));
        }

        if (l >= abs(_v[a] - _v[_next])) {
            l -= abs(_v[a] - _v[_next]);
            a = _next;
        }
        else
            continue ;
    }

    return a;
}

int where[200005];

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> v[i].val;
        v[i].pos = i;
    }

    sort(v + 1, v + n + 1);

    for (int i = 1; i <= n; i++) {
        where[v[i].pos] = i;
        _v[i] = v[i].val;
    }

    int a, l;
    while (m--) {
        cin >> a >> l;
        cout << v[get_ans(where[a], l)].pos << '\n';
    }

    return 0;
}