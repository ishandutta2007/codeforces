#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base :: sync_with_stdio(false);

    int N;
    cin >> N; N --;

    int aux, v;
    cin >> aux >> v;

    stack <bool> overtake;
    stack <int> speeds;

    int ans = 0;
    while (N --) {
        int type;
        cin >> type;

        if (type == 1) {
            cin >> v;
            while (!speeds.empty() && speeds.top() < v) {
                ++ ans;
                speeds.pop();
            }
        }
        else if (type == 2) {
            while (!overtake.empty() && overtake.top() == false) {
                ++ ans;
                overtake.pop();
            }
        }
        else if (type == 3) {
            int sp;
            cin >> sp;
            speeds.push(sp);
            while (!speeds.empty() && speeds.top() < v) {
                ++ ans;
                speeds.pop();
            }
        }
        else if (type == 4) {
            overtake.push(true);
        }
        else if (type == 5) {
            while (!speeds.empty())
                speeds.pop();
        }
        else if (type == 6) {
            overtake.push(false);
        }
    }

    cout << ans << '\n';
    return 0;
}