#include <iostream>
#include <set>

using namespace std;

const int MAXN = 55;
char c[MAXN][MAXN], face[] = {'f', 'a', 'c', 'e'};

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> c[i][j];
    int ans = 0;
    for(int i = 0; i + 1 < n; i++)
        for(int j = 0; j + 1 < m; j++) {
            set<char> st;
            st.insert(c[i][j]);
            st.insert(c[i][j + 1]);
            st.insert(c[i + 1][j]);
            st.insert(c[i + 1][j + 1]);
            bool bad = false;
            for(int k = 0; k < 4; k++)
                if(st.find(face[k]) == st.end()) {
                    bad = true;
                    break;
                }
            if(!bad)
                ans++;
        }
    cout << ans << '\n';
    return 0;
}