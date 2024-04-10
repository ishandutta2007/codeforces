#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, mint, maxt, t, rmint, rmaxt;
    cin >> n >> m >> mint >> maxt >> t;
    rmint = t;
    rmaxt = t;
    for(int i = 1; i < m; i++) {
        cin >> t;
        rmint = min(rmint, t);
        rmaxt = max(rmaxt, t);
    }
    if(rmint < mint || rmaxt > maxt || (rmint > mint && rmaxt < maxt && m == n - 1))
        cout << "Incorrect\n";
    else
        cout << "Correct\n";
    return 0;
}