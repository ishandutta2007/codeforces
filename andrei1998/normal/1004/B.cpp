#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N;
    for (int i = 0; i < N; ++ i)
        cout << i % 2;
    cout << endl;
    return 0;
}