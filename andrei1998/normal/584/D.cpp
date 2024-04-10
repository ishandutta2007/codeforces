#include <bits/stdc++.h>

using namespace std;

bool isPrime(int nr) {
    if (nr <= 1)
        return false;
    for (int i = 2; i * i <= nr; ++ i)
        if (nr % i == 0)
            return false;
    return true;
}

int main()
{
    int N;
    cin >> N;

    if (N == 3) {
        cout << "1\n";
        cout << "3\n";
        return 0;
    }
    else if (N == 5) {
        cout << "2\n";
        cout << "2 3\n";
        return 0;
    }
    else if (N == 7) {
        cout << "3\n";
        cout << "2 2 3\n";
        return 0;
    }
    else if (N == 9) {
        cout << "3\n";
        cout << "3 3 3\n";
        return 0;
    }

    vector <int> v;
    v.push_back(3);
    N -= 3;

    for (int i = 2; i <= 40000; ++ i)
        if (isPrime(i) && isPrime(N - i)) {
            v.push_back(i);
            v.push_back(N - i);
            break;
        }

    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); ++ i)
        cout << v[i] << " \n"[i == v.size()];
    return 0;
}