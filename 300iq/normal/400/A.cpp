#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

vector <int> find(string s) {
    vector<int> sol;
    int r[6] = {1, 2, 3, 4, 6, 12};

    for (int i = 0; i < 6; ++i) {
        int a, b;
        a = r[i];
        b = 12 / a;
        for (int j = 1; j <= b; ++j) {
            int flag = 0;
            for (int k = 1; k <= a; ++k) {
                flag += 1 * (s[(j - 1) + (k - 1) * b] == 'X');
            }
            if (flag == a) {
                sol.push_back(a);
                break;
            }
        }
    }
    return sol;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        string s, ans = "";
        cin >> s;
        vector<int> sol;
        sol = find(s);
        for (int j = 0; j < sol.size(); ++j) {
            ostringstream a, b;
            a << sol[j];
            b << 12 / sol[j];
            ans += " " + a.str() + "x" + b.str();
        }
        cout << sol.size() << ans << endl;
    }
}