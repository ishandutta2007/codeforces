#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int prev = 1000000001;
    for (int i = 0; i < n; i++) {
        int w, h;
        cin >> w >> h;
        if (w < h) swap(w, h);
        if (prev == w) prev = w;
        else if (prev > w) prev = w;
        else if (prev < w && prev >= h) prev = h;
        else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}