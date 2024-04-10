#include <iostream>

using namespace std;

const int N = 4;
int a[N], b[N];

int main() {
    ios_base::sync_with_stdio(false);
    for(int i = 0; i < N; i++)
        cin >> a[i] >> b[i];
    for(int i = 0; i < 2; i++) {
        bool win = true;
        for(int j = 0; j < 2; j++)
            if(a[i] <= b[2 + (j ^ 1)] || b[i ^ 1] <= a[2 + j])
                win = false;
        if(win) {
            cout << "Team 1\n";
            return 0;
        }
    }
    for(int i = 0; i < 2; i++) {
        bool draw = true;
        for(int j = 0; j < 2; j++)
            if(a[i] < b[2 + (j ^ 1)] && b[i ^ 1] < a[2 + j])
                draw = false;
        if(draw) {
            cout << "Draw\n";
            return 0;
        }
    }
    cout << "Team 2\n";
    return 0;
}