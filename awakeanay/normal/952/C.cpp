#include <iostream>
#include <string>
#include <cmath>

int main()
{
    int N;
    std::cin >> N;
    
    int last = -1;
    for(int i = 0; i < N; i++)
    {
        int input;
        std::cin >> input;
        if(abs(input - last) >= 2 && last != -1)
        {
            std::cout << "NO" << std::endl;
            return 0;
        }
        last = input;
    }
    
    std::cout << "YES" << std::endl;
    
    return 0;
}