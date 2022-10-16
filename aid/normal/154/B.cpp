#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int MAXN = 100 * 1000 + 5;
vector<int> fact[MAXN];
map<int, int> mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int x = i;
        for(int j = 2; j * j <= x; j++)
            if(!(x % j)) {
                fact[i].push_back(j);
                while(!(x % j))
                    x /= j;
            }
        if(x > 1)
            fact[i].push_back(x);
    }
    bool one = false;
    for(int i = 0; i < m; i++) {
        char c;
        int pos;
        cin >> c >> pos;
        if(c == '+') {
            if(pos == 1) {
                if(one)
                    cout << "Already on\n";
                else {
                    one = true;
                    cout << "Success\n";
                }
                continue;
            }
            int found = -1;
            for(size_t j = 0; j < fact[pos].size(); j++)
                if(mp.find(fact[pos][j]) != mp.end()) {
                    found = mp[fact[pos][j]];
                    break;
                }
            if(found == -1) {
                for(size_t j = 0; j < fact[pos].size(); j++)
                    found = mp[fact[pos][j]] = pos;
                cout << "Success\n";
            }
            else {
                if(found == pos)
                    cout << "Already on\n";
                else
                    cout << "Conflict with " << found << '\n';
            }
        }
        else {
            if(pos == 1) {
                if(one) {
                    one = false;
                    cout << "Success\n";
                }
                else
                    cout << "Already off\n";
                continue;
            }
            if(mp.find(fact[pos][0]) != mp.end() && mp[fact[pos][0]] == pos) {
                for(size_t j = 0; j < fact[pos].size(); j++)
                    mp.erase(fact[pos][j]);
                cout << "Success\n";
            }
            else
                cout << "Already off\n";
        }
    }
    return 0;
}