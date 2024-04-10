#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> l, r;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    for(size_t i = 0; i < s.length(); i++)
        if(s[i] == 'l')
            r.push_back(i);
        else
            l.push_back(i);
    reverse(r.begin(), r.end());
    for(size_t i = 0; i < l.size(); i++)
        cout << l[i] + 1 << '\n';
    for(size_t i = 0; i < r.size(); i++)
        cout << r[i] + 1 << '\n';
    return 0;
}