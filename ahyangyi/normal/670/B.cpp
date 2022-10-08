#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    long long k;
    std::cin >> n >> k;

    std::vector<int> id(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> id[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (k <= i + 1)
        {
            std::cout << id[k - 1] << std::endl;
            break;
        }
        k -= i + 1;
    }
    return 0;
}