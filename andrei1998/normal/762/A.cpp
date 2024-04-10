#include <iostream>
#include <algorithm>
#include <vector>

#define lint long long int
using namespace std;

int main()
{
    lint N;
    cin >> N;

    vector <lint> v;

    for (int i = 1; 1LL * i * i <= N; ++ i)
        if (N % i == 0) {
            v.push_back(i);
            if (1LL * i * i < N)
                v.push_back(N / i);
        }

    int k;
    cin >> k;

    if (k > v.size())
        cout << "-1\n";
    else {
        nth_element(v.begin(), v.begin() + k - 1, v.end());
        cout << v[k - 1] << '\n';
    }
    return 0;
}