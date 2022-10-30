#include <cstdio>
#include <queue>
#include <algorithm> 

using namespace std;



int main()
{
    int n;
    scanf("%d\n", &n);
    int max_size = 0;
    int curr_size = 0;
    int t, c;
    int prev_t = -1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d\n", &t, &c);
        
        int d =  - prev_t + t;
        curr_size = max(curr_size - d, 0);
        curr_size += c;
        prev_t = t;
        max_size = max(max_size, curr_size);        
    }
    int end_t = prev_t + curr_size;
    printf("%d %d", end_t, max_size);
}