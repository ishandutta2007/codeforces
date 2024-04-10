#include <bits/stdc++.h>
using namespace std;

pair<vector<pair<int, int>>, vector<int>> solve(vector<int> V)
{
    vector<pair<int, int>> op;
    vector<int> part;

    int cter = 0;
    // reverse first a element
    auto rev = [&](int a)
    {
        assert(a <= (int)V.size());
        for (int i = a - 1; i >= 0; --i)
            op.emplace_back(cter + 2 * a - 1 - i, V[a - 1 - i]);
        reverse(V.begin(), V.begin() + a);
        part.push_back(2 * a);
        cter += 2 * a;
    };

    int N = (int)V.size();
    for (int i = 0; i < N / 2; ++i)
    {
        int last_elem = V[N - 1 - 2 * i];
        int elem_idx = find(V.begin(), V.end(), last_elem) - V.begin();
        rev(elem_idx + 1);
        rev(N - 1 - 2 * i);
    }
    for (int i = 0; i < N / 2; i++)
        part.push_back(2);
    return {op, part};
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> V(N);
        for (int &x : V)
            cin >> x;
        bool ts = (N % 2 == 0);
        auto t = V;
        sort(t.begin(), t.end());
        for (int i = 0; i < N / 2; i++)
            if (t[2 * i] != t[2 * i + 1])
                ts = false;
        if (!ts)
        {
            cout << -1 << endl;
        }
        else
        {
            auto [a, b] = solve(V);
            cout << a.size() << endl;
            for (auto [x, y] : a)
                cout << x << " " << y << endl;
            cout << b.size() << endl;
            for (int x : b)
                cout << x << " ";
            cout << endl;
        }
    }
}