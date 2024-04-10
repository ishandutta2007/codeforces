#include <iostream>
#include <string>
#include <stack>

using namespace std;

typedef long long int lint;

lint N = 15;
string ans;
void build(lint node, lint put, lint val) {
    if (put == 1)
        return ;
    if (val == node)
        return ;

    if (val < node) {
        ans += 'L';
        build(node - (put >> 1), put >> 1, val);
    }
    else {
        ans += 'R';
        build(node + (put >> 1), put >> 1, val);
    }
}

stack <lint> stk;

lint res;
void solve(lint node, lint put, int pos) {
    stk.push(node);
    if (pos == ans.size()) {
        res = node;
        return ;
    }

    char ch = ans[pos];
    if (ch == 'U') {
        if (node == (N + 1) / 2) {
            stk.pop();
            solve(node, put, pos + 1);
        }
        else {
            stk.pop();
            node = stk.top();
            stk.pop();
            solve(node, put * 2, pos + 1);
        }
        return ;
    }

    if (put == 1) {
        stk.pop();
        solve(node, put, pos + 1);
    }
    else if (ch == 'L')
        solve(node - (put >> 1), put >> 1, pos + 1);
    else
        solve(node + (put >> 1), put >> 1, pos + 1);
}

int main()
{
    int q;
    cin >> N >> q;
    while (q --) {
        lint nr;
        cin >> nr;
        ans = "";
        build((N + 1) / 2, (N + 1) / 2, nr);

        string str;
        cin >> str;
        ans += str;

        solve((N + 1) / 2, (N + 1) / 2, 0);

        cout << res << '\n';
    }

    return 0;
}