#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 10011
#define maxP 111
#define inf 100000000

const int limit = 101;

struct expr {
    int ops, i;
    int dp_min[maxP], dp_max[maxP];

    void init() {
        ops = 0;
        for (i = 0; i <= limit; i++) {
            dp_min[i] = inf;
            dp_max[i] = -inf;
        }
    }

    expr() {
        init();
    }
};

int n, i, P, M, v;
char s[maxN];

vector<expr> data;
expr T1, T2;

bool is_digit(char c) {
    return '0' <= c && c <= '9';
}

void upd_min(int& a, int b) {
    a = min(a, b);
}

void upd_max(int& a, int b) {
    a = max(a, b);
}

expr get_combo(int sgn, int dif) {
    int i, j;
    expr ans;

    ans.init();
    ans.ops = T1.ops + T2.ops + 1;
    for (i = 0; i <= limit; i++) {
        if (T1.dp_min[i] >= inf) continue;

        for (j = 0; i + j <= limit; j++) {
            if (T2.dp_min[j] >= inf) continue;

            upd_min(ans.dp_min[i + j + dif], T1.dp_min[i] + sgn * T2.dp_min[j]);
            upd_min(ans.dp_min[i + j + dif], T1.dp_min[i] + sgn * T2.dp_max[j]);
            upd_min(ans.dp_min[i + j + dif], T1.dp_max[i] + sgn * T2.dp_min[j]);
            upd_min(ans.dp_min[i + j + dif], T1.dp_max[i] + sgn * T2.dp_max[j]);

            upd_max(ans.dp_max[i + j + dif], T1.dp_min[i] + sgn * T2.dp_min[j]);
            upd_max(ans.dp_max[i + j + dif], T1.dp_min[i] + sgn * T2.dp_max[j]);
            upd_max(ans.dp_max[i + j + dif], T1.dp_max[i] + sgn * T2.dp_min[j]);
            upd_max(ans.dp_max[i + j + dif], T1.dp_max[i] + sgn * T2.dp_max[j]);
        }
    }

    for (i = 0; i <= limit; i++) {
        upd_min(ans.dp_min[i], inf);
        upd_max(ans.dp_min[i], -inf);

        upd_min(ans.dp_max[i], inf);
        upd_max(ans.dp_max[i], -inf);
    }

    return ans;
}

void get_best() {
    int i;

    for (i = 0; i <= limit; i++) {
        upd_min(T1.dp_min[i], T2.dp_min[i]);
        upd_max(T1.dp_max[i], T2.dp_max[i]);
    }
}

void execute_operation() {
    T1 = data[data.size() - 2];
    T2 = data[data.size() - 1];
    data.pop_back(); data.pop_back();

    expr addition = get_combo(1, (P < M ? +1 : 0));
    expr substraction = get_combo(-1, (P < M ? 0 : +1));

    T1 = addition;
    T2 = substraction;

    get_best();
    data.pb(T1);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%s%d%d", s + 1, &P, &M);
    n = strlen(s + 1);

    for (i = 1; i <= n; i++) {
        if (is_digit(s[i])) {
            data.emplace_back();
            data.back().ops = 0;
            data.back().dp_min[0] = data.back().dp_max[0] = s[i] - '0';
            continue;
        }

        if (s[i] == '(') {
            continue;
        }

        if (s[i] == '?') {
            continue;
        }

        if (s[i] == ')')
            execute_operation();

    }


    printf("%d", data[0].dp_max[min(P, M)]);



    return 0;
}