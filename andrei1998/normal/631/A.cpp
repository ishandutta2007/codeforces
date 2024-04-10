#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int a = 0;
    for (int i = 0; i < N; ++ i) {
        int x;
        cin >> x;
        a |= x;
    }
    int b = 0;
    for (int i = 0; i < N; ++ i) {
        int y;
        cin >> y;
        b |= y;
    }

    cout << a + b << '\n';
    return 0;
}