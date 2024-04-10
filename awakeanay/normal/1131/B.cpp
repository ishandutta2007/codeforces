#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    
    long long answer = 1;
    long long max = 0;
    int last = 0;
    for(int i = 0; i < n; i++)
    {
        long long a, b;
        std::cin >> a >> b;
        
        if(a == 0 && b == 0)
            continue;
        
        int state;
        
        if(a == b)
            state = 0;
        else
            state = (b > a) + 1;
        
        if(state == 0 && last == 0)
            answer += a - max;
        else if(last == 1 && state == 1 && b - max >= 0)
            answer += b - max + 1;
        else if(last == 2 && state == 2 && a - max >= 0)
            answer += a - max + 1;  
        else if(state == 0)
            answer += a - max + 1;
        else if(state == 1 && last == 0)
            answer += b - max;
        else if(state == 2 && last == 0)
            answer += a - max;
        else if(state == 1 && last == 2)
            answer += b - max + 1;
        else if(state == 2 && last == 1)
            answer += a - max + 1;
        
        last = state;
        max = std::max(a, b);
    }
    
    std::cout << answer;
}