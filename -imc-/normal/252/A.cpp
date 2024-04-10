#include <cstdio>
#include <limits>

using namespace std;

const int maxN = 105;
int array[maxN];

int main()
{
    int n = 0;
    scanf ("%i", &n);
    
    for (int i = 0; i < n; i++)
        scanf ("%i", &array[i]);
    
    int max = -std::numeric_limits <int>::max();
    
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            int xorValue = 0;
            
            for (int k = i; k <= j; k++)
                xorValue ^= array[k];
            
            if (xorValue > max)
                max = xorValue;
        }
        
    printf ("%i\n", max);
    
    return 0;
}