#include <iostream>
#include <algorithm>

int main()
{
    long long x[3], n;

    std::cin >> x[0] >> x[1] >> x[2] >> n;
    std::sort(x, x + 3);

    long long answer = 1;
    for (int i = 0; i < 3; ++i)
    {
        long long cut = n / (3 - i);
        if (cut > x[i] - 1)
        {
            cut = x[i] - 1;
        }
        answer *= cut + 1;
        n -= cut;
    }

    std::cout << answer << std::endl;

    return 0;
}