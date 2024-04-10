#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;

    long long total = 0;
    vector<long long> stack = {1};
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        if (s == "add")
        {
            long long cur = stack[stack.size() - 1];
            if (cur == -1)
            {
                cout << "OVERFLOW!!!" << endl;
                return 0;
            }
            total += cur;
            if (total >= 4294967296LL)
            {
                cout << "OVERFLOW!!!" << endl;
                return 0;
            }
        }
        else if (s == "for")
        {
            long long x;
            cin >> x;

            x *= stack[stack.size() - 1];
            if (x < 0 || x >= 4294967296LL)
            {
                x = -1;
            }
            stack.push_back(x);
        }
        else
        {
            stack.pop_back();
        }
    }

    cout << total << endl;

    return 0;
}