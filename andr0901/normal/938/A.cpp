#include <iostream>

using namespace std;

int main()
{
    int n;
    string a;
    cin >> n >> a;
    for (int i = 0; i < a.size() - 1; i++) {
        if ((a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' || a[i] == 'y') && (a[i + 1] == 'a' || a[i + 1] == 'e' || a[i +1] == 'i' || a[i + 1] == 'o' || a[i + 1] == 'u' || a[i + 1] == 'y')) {
            a.erase (a.begin() + i + 1, a.begin() + i + 2);
            i--;
        }
    }
    cout << a;
    return 0;
}