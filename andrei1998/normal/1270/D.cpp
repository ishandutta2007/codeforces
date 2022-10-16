#include <bits/stdc++.h>

using namespace std;

int N, K;
int ask_without(int x) {
    cout << "?";
    for (int i = 1; i <= K + 1; ++i) {
        if (i != x) {
            cout << ' ' << i;
        }
    }
    cout << endl;
    int pos, apos;
    cin >> pos >> apos;
    return apos;
}

int main() {
    cin >> N >> K;
    vector<int> answers(K + 1);
    for (int i = 1; i <= K + 1; ++i) {
        answers[i - 1] = ask_without(i);
    }
    sort(answers.begin(), answers.end());
    int cnt_large = 0;
    for (int i = 0; i <= K; ++i) {
        if (answers[i] == answers[K]) {
            ++cnt_large;
        }
    }
    cout << "! " << cnt_large << endl;
    return 0;
}