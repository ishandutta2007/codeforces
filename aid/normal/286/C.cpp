#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 1000 * 1000 + 5;
int p[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> p[i];
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int q;
        cin >> q;
        q--;
        p[q] *= -1;
    }
    stack<int> st;
    for(int i = n - 1; i >= 0; i--)
        if(p[i] < 0)
            st.push(-p[i]);
        else if(!st.empty() && p[i] == st.top())
            st.pop();
        else {
            st.push(p[i]);
            p[i] *= -1;
        }
    if(!st.empty()) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++)
        cout << p[i] << ' ';
    cout << '\n';
    return 0;
}