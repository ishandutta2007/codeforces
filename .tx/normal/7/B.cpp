#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
};

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

int mem[111];
int last_id = 0;
int m;

int do_alloc(int n) {
    int csz = 0;
    int i;
    for (i = 0; i < m; i++) {
        if (mem[i] == 0) {
            csz++;
        } else {
            csz = 0;
        }
        if (csz == n) {
            break;
        }
    }

    if (i == m) {
        return -1;
    }

    last_id++;
    for (int j = 0; j < n; j++) {
        mem[i--] = last_id;
    }
    return last_id;
}

bool do_erase(int id) {
    bool was = false;
    for (int i = 0; i < m; i++) {
        if (mem[i] == id) {
            was = true;
            mem[i] = 0;
        }
    }
    return was;
}

void do_defragment() {
    int last = 0;
    for (int i = 0; i < m; i++) {
        if (mem[i] != 0) {
            mem[last++] = mem[i];
        }
    }
    for (int i = last; i < m; i++) {
        mem[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(t);
    sci(m);

    while (t-- > 0) {
        scids(s);
        if (s == "alloc") {
            scid(n);
            int id = do_alloc(n);
            if (id != -1) {
                cout << id << "\n";
            } else {
                cout << "NULL\n";
            }
        } else if (s == "erase") {
            scid(id);
            if (id <= 0 || !do_erase(id)) {
                cout << "ILLEGAL_ERASE_ARGUMENT\n";
            }
        } else { // s == "defragment"
            do_defragment();
        }
    }

    return 0;
}