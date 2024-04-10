#include <cstdio>
#include <vector>

using namespace std;

const int MODULE = 1000000007;

typedef long long ll;

ll c[1005][1005];

void calcCnk()
{
    for (int n = 0; n < 1005; n++)
        for (int k = 0; k < 1005; k++)
        {
            if (n == 0)
                c[n][k] = (k == 0 ? 1 : 0);
            else if (k == 0)
                c[n][k] = 1;
            else
                c[n][k] = c[n - 1][k] + c[n - 1][k - 1];
            
            c[n][k] %= MODULE;
        }
        
    //printf("%lld\n", c[5][2]);
}

int main()
{
    calcCnk();
    
    int n;
    scanf("%d", &n);
    
    vector<int> nc(n);
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nc[i]);
        total += nc[i];
    }
    
    ll answer = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        total--;
        nc[i]--;
        
        answer *= c[total][nc[i]];
        answer %= MODULE;
        
        total -= nc[i];
    }
    
    printf("%lld\n", answer);
    
    return 0;
}