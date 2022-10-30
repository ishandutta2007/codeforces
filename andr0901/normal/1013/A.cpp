#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int s1 = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        s1 += t;
    }
    int s2 = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        s2 += t;
    }
    if (s1 < s2) cout << "No";
    else cout << "Yes";
    return 0;
}