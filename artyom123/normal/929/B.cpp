#include <bits/stdc++.h>
using namespace std;
struct m{
    int x;
    int y;
    int s;
};

bool comp (m i, m j) {
    return (i.s < j.s);
}
int main()
{
    int answer = 0;
    int n, k;
    cin >> n >> k;
    char a[n][12];
    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < 12; j++) {
            cin >> a[i][j];
        }
    }
    vector <m> b;
    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < 12; j++) {
            if ( a[i][j] == 'S') {
                if ( j != 0 && j != 11 && a[i][j - 1] != '.' && a[i][j - 1] != '-' && a[i][j + 1] != '.' && a[i][j + 1] != '-') {
                    answer += 2;

                }
                else if ( (a[i][j - 1] != '.' && a[i][j - 1] != '-' && j != 0) || (a[i][j + 1] != '.' && a[i][j + 1] != '-' && j != 11)){
                    answer += 1;

                }
            }
            if ( a[i][j] == '.') {
                if ( j == 0 && a[i][j + 1] == 'S') {
                    m now;
                    now.x = i;
                    now.y = j;
                    now.s = 1;
                    b.push_back(now);
                }
                else if ( j == 0) {
                    m now;
                    now.x = i;
                    now.y = j;
                    now.s = 0;
                    b.push_back(now);
                }
                else if (j == 11 && a[i][j - 1] == 'S') {
                    m now;
                    now.x = i;
                    now.y = j;
                    now.s = 1;
                    b.push_back(now);
                }
                else if (j == 11) {
                    m now;
                    now.x = i;
                    now.y = j;
                    now.s = 0;
                    b.push_back(now);
                }
                else if ( a[i][j - 1] == 'S' && a[i][j + 1] == 'S') {
                    m now;
                    now.x = i;
                    now.y = j;
                    now.s = 2;
                    b.push_back(now);
                }
                else if ( a[i][j - 1] == 'S' || a[i][j + 1] == 'S') {
                    m now;
                    now.x = i;
                    now.y = j;
                    now.s = 1;
                    b.push_back(now);
                }
                else {
                    m now;
                    now.x = i;
                    now.y = j;
                    now.s = 0;
                    b.push_back(now);
                }
            }
            }
        }

        sort(b.begin(), b.end(), comp);
        for ( int i = 0; i < k; i++) {
            a[b[i].x][b[i].y] = 'x';
            answer += b[i].s;
        }
        cout << answer << endl;
        for ( int i = 0; i < n; i++) {
            for ( int j = 0; j < 12; j++) {
                cout << a[i][j];
            }
            cout << endl;
        }



    return 0;
}