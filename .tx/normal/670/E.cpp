#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

struct list {
    list* prev = 0;
    list* next = 0;
    list* pair = 0;
    char v;
};

char s[555555];

int main() {
    sciiid(n, m, p);
    scanf("\n%s", s);
    list* head = new list();
    stack<list*> st;
    list* cur = head;
    for (int i = 0; i < n; i++) {
        list* nx = new list();
        nx->v = s[i];
        cur->next = nx;
        nx->prev = cur;
        if (s[i] == '(') {
            st.push(nx);
        } else {
            list* pp = st.top();
            st.pop();
            pp->pair = nx;
            nx->pair = pp;
        }
        cur = nx;
    }
    cur = head;
    for (int i = 0; i < p; i++) {
        cur = cur->next;
    }

    scanf("\n%s", s);
    for (int i = 0; i < m; i++) {
        char c = s[i];
        if (c == 'L') {
            cur = cur->prev;
        } else if (c == 'R') {
            cur = cur->next;
        } else {
            if (cur->v == '(') {
                cur = cur->pair;
            }
            cur->pair->prev->next = cur->next;
            if (cur->next) {
                cur->next->prev = cur->pair->prev;
                cur = cur->next;
            } else {
                cur = cur->pair->prev;
            }
        }
    }

    cur = head->next;
    while (cur) {
        cout << cur->v;
        cur = cur->next;
    }

    return 0;
}