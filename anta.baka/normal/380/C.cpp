#include <stdio.h>
#include <vector>
#include <stack>
#include <utility>
using namespace std;
const int N = 1e6 + 50;
int a[N], f[N], ans[N][3];
char s[N];
vector<int> ql[N], qr[N];
pair<int,int> q[N];

void add(int p, int x) {
    for(int i = p; i < N; i |= i+1)
        f[i] += x;
}

int sum(int p) {
    int res = 0;
    for(int i = p; i >= 0; i &= i+1, i--)
        res += f[i];
    return res;
}

int main() {
    int qn;
    scanf("%s%d", s, &qn);
    int n = strlen(s);
    stack<int> st;
    for(int i = 0; i < n; i++)
        if(s[i] == '(')
            st.push(i);
        else {
            if(st.empty())
                a[i] = n;
            else {
                a[i] = st.top();
                a[st.top()] = i;
                st.pop();
            }
        }
    while(!st.empty()) {
        a[st.top()] = n;
        st.pop();
    }
    for(int i = 0; i < qn; i++) {
        scanf("%d%d", &q[i].first, &q[i].second);
        q[i].first--; q[i].second--;
        qr[q[i].second].push_back(i);
        if(q[i].first)
            ql[q[i].first-1].push_back(i);
    }
    for(int i = 0; i < n; i++) {
        add(a[i], 1);
        for(int j = 0, sz = (int)ql[i].size(); j < sz; j++) {
            ans[ql[i][j]][0] = sum(q[ql[i][j]].first-1);
            ans[ql[i][j]][1] = sum(N-1) - sum(q[ql[i][j]].second);
        }
        for(int j = 0, sz =(int)qr[i].size(); j < sz; j++)
            ans[qr[i][j]][2] = (q[qr[i][j]].second - q[qr[i][j]].first + 1) - (sum(q[qr[i][j]].first-1) - ans[qr[i][j]][0]) - (sum(N-1) - sum(q[qr[i][j]].second) - ans[qr[i][j]][1]);
    }
    for(int i = 0; i < qn; i++)
        printf("%d\n", ans[i][2]);
    return 0;
}