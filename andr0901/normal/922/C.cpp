#include <iostream>
#include <set>

using namespace std;

int main()
{
    long long int n, k;
    set <int> a;
    cin >> n >> k;
    for (long long int i = 1; i <= k; i++) {
        if (a.find(n % i) != a.end()) {
            cout << "No";
            return 0;
        }
        else a.insert(n % i);
    }
    cout << "Yes";
    return 0;
}