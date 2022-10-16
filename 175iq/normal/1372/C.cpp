#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <chrono>
#include <vector>
#include <cmath>
using namespace std;
using llong = long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using rndi = uniform_int_distribution<int>;
using rndll = uniform_int_distribution<llong>;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& i: a) cin >> i;
        if (is_sorted(a.begin(), a.end()))
            cout << "0\n";
        else {
            int i = -1;
            while (a[i + 1] == i + 2) ++i;
            int j = n;
            while (a[j - 1] == j) --j;
            bool one = true;
            for (int k = i + 1; k < j; ++k)
                if (a[k] == k + 1)
                    one = false;
            if (one)
                cout << "1\n";
            else
                cout << "2\n";
        }
    }
}