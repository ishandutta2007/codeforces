#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

ll d[55];

int main()
{
    d[0] = 1;
    d[1] = 1;
    for (int n = 2; n < 55; n++)
        d[n] = d[n - 1] + d[n - 2];
    
    int n;
    ll k;
    cin >> n >> k;
    
    int counter = 1;
    while (n > 0)
    {
        n--;
        
        if (k - d[n] <= 0)
        {
            printf("%d ", counter);
            counter++;
        }
        else
        {
            k -= d[n];
            n--;
            printf("%d %d ", counter + 1, counter);
            counter += 2;
        }
    }
    printf("\n");

    return 0;
}