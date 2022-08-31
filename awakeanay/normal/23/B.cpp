#include <iostream>

int main()
{
    int t;
    std::cin >> t;
    
    while(t--)
    {
        int n;
        std::cin >> n;
        std::cout << std::max(0,n-2) << std::endl;
    }

    return 0;
}