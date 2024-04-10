#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;

int getMaxEqual(int maxSpeed)
{
    int answer = 0;
    
    vector<int> now = a;
    for (auto& it: now)
    {
        it = min(it, maxSpeed);
        if (it == maxSpeed)
            answer++;
    }
    
    return answer;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    
    a.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    int low = 0, high = 1e9;
    
    while (low != high)
    {
        int m = (low + high + 1) / 2;
        int can = getMaxEqual(m);
        
        if (can < k)
            high = m - 1;
        else
            low = m;
    }
    
    printf("%d\n", low);
    
    return 0;
}