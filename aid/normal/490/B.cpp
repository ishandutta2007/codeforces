#include <iostream>
#include <map>
using namespace std;

const int MAXN = 200 * 1000 + 5, MAXM = 1000 * 1000 + 5;
int nxt[MAXN], prev[MAXN], ans[MAXN];
char used[MAXM];
map<int, int> mp;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int s = -1;
    for(int i = 0; i < n; i++) {
        cin >> prev[i] >> nxt[i];
        prev[i]--;
        nxt[i]--;
        used[nxt[i]] = true;
        mp[prev[i]] = i;
        if(prev[i] == -1)
            s = i;
    }
    int id = -1;
    for(int i = 0; i < n; i++)
        if(!used[prev[i]]) {
            id = prev[i];
            break;
        }
    cout << id + 1 << ' ';
    for(int i = 0; i + 1 < n; i++) {
        int tmp = nxt[s];
        s = mp[id];
        id = tmp;
        cout << id + 1 << ' ';
    }
    cout << '\n';
    return 0;
}