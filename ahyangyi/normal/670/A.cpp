#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    std::cout << n / 7 * 2 + (n % 7 == 6) << " " << n / 7 * 2 + std::min(2, n % 7) << std::endl;

    return 0;
}