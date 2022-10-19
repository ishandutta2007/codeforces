#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cassert>
#include <iostream>

using namespace std;

const int MAXN = 100007;
int n, m, s, asgn[MAXN];
struct Bug { int a, id; } bugs[MAXN];
struct Student
{
    int b, c, id;
    bool operator< (const Student &st) const
    {
        return c > st.c;
    }
} students[MAXN];
priority_queue<Student> pq;

bool check(int days)
{
    long long cost = 0;
    while (!pq.empty()) pq.pop();
    for (int b_i = 0, s_i = 0; b_i < m; b_i += days) {
        for (; s_i < n && students[s_i].b >= bugs[b_i].a; ++s_i) pq.push(students[s_i]);
        if (pq.empty()) return 0;
        auto st = pq.top(); pq.pop();
        cost += st.c;
        for (int i = b_i; i < min(b_i + days, m); ++i) asgn[bugs[i].id] = st.id;
    }
    return cost <= s;
}

int main()
{
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < m; ++i) scanf("%d", &bugs[i].a);
    for (int i = 0; i < m; ++i) bugs[i].id = i;
    for (int i = 0; i < n; ++i) scanf("%d", &students[i].b);
    for (int i = 0; i < n; ++i) scanf("%d", &students[i].c);
    for (int i = 0; i < n; ++i) students[i].id = i + 1;

    sort(bugs, bugs + m, [&](Bug b1, Bug b2) { return b1.a > b2.a; });
    sort(students, students + n, [&](Student s1, Student s2) { return s1.b > s2.b; });

    if (!check(m)) return cout << "NO" << endl, 0;
    int lo = 1, hi = m;
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    assert(check(lo));
    cout << "YES" << endl;
    for (int i = 0; i < m; ++i) cout << asgn[i] << ' ';
}