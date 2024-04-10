#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

pair <int, int> simulate(bool turn, int i, int j, int cnt, int N) {
    while (cnt < N) {
        if (!turn)
            i ++;
        else
            j ++;
        turn ^= 1;
        ++ cnt;
    }
    return make_pair(i, j);
}

int main()
{
    string oleg;
    string igor;
    cin >> oleg >> igor;

    int N = oleg.size();

    sort(oleg.begin(), oleg.end());
    sort(igor.begin(), igor.end(), greater <char>());

    string ans;

    //Before turn point
    int i = 0, j = 0;
    bool turn = false;
    while (ans.size() < N) {
        if (oleg[i] >= igor[j])
            break;
        if (!turn)
            ans += oleg[i ++];
        else
            ans += igor[j ++];
        turn ^= 1;
    }

    int cnt = ans.size();
    ans.resize(N);

    //After turn point
    int where = N - 1;

    pair <int, int> aux = simulate(turn, i, j, cnt, N);
    i = aux.first - 1;
    j = aux.second - 1;

    while (cnt < N) {
        if (!turn)
            ans[where --] = oleg[i --];
        else
            ans[where --] = igor[j --];
        turn ^= 1;
        ++ cnt;
    }

    cout << ans << '\n';
    return 0;
}