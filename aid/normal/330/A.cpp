#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int r, c;
    cin >> r >> c;
    vector< vector< pair<char, char> > > v(r, vector< pair<char, char> >(c));
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++) {
            char ch;
            cin >> ch;
            if(ch == 'S') {
                for(int k = 0; k < r; k++)
                    v[k][j].first = true;
                for(int k = 0; k < c; k++)
                    v[i][k].second = true;
            }
        }
    int ans = 0;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(!(v[i][j].first && v[i][j].second))
                ans++;
    cout << ans << '\n';
}