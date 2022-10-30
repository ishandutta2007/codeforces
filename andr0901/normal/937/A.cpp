#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    set <int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x != 0) a.insert (x);
    }
    cout << a.size();
    return 0;
}