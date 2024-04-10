#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MODULO = 1000000007;

long long sum(long long limit)
{
    int start[2] = {1, 2};
    int oddity = 0;
    long long count = 1;
    long long result = 0;

    while (limit > 0)
    {
        long long len;
        if (count <= limit)
        {
            len = count;
        }
        else
        {
            len = limit;
        }
        limit -= len;

        result += (start[oddity] + len - 1) % MODULO * (len % MODULO) % MODULO;
        result %= MODULO;

        start[oddity] = (start[oddity] + len * 2) % MODULO;
        oddity = 1 - oddity;
        count = count * 2;
    }

    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);

    long long l, r;
    cin >> l >> r;
    cout << (sum(r) - sum(l - 1) + MODULO) % MODULO << endl;

    return 0;
}