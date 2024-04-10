#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

const int maxN = 100010;
int begin[maxN];

struct event
{
    bool begin;
    int x, id;

    bool operator< (const event& e) const
    {
        if (x != e.x)
            return x < e.x;
        
        if (begin != e.begin)
            return begin;
        
        return id < e.id;
    }
};

std::vector <event> events;

int main()
{
    int n = 0, d = 0;
    std::cin >> n >> d;
    
    for (int i = 0; i < n; i++) 
    {
        int x = 0;
        std::cin >> x;
        
        event e = { true, x, i };
        events.push_back (e);
        event v = { false, x + d, i };
        events.push_back (v);
    }
    
    std::sort (events.begin(), events.end());
    
    int numBegins = 0;
    long long answer = 0;
    
    for (int i = 0; i < (int)events.size(); i++)
    {
        if (events[i].begin)
        {
            numBegins++;
            begin[events[i].id] = numBegins;
        }
        else
        {
            long long x = numBegins - begin[events[i].id];
            answer += x * (x - 1) / 2;
            //std::cout << x << std::endl;
        }
    }
    
    std::cout << answer << std::endl;
    return 0;
}