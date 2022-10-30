#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;
typedef unsigned int uint;

uint read_ip()
{
    uint p1, p2, p3, p4;
    scanf("%d.%d.%d.%d\n", &p1, &p2, &p3, &p4);
    return (p1 << 24) + (p2 << 16) + (p3 << 8) + p4;
}

void write_ip(uint ip)
{
    printf("%d.%d.%d.%d\n", (ip >> 24) & 255, (ip >> 16) & 255,
        (ip >> 8) & 255, ip & 255);
}

int a[100005];
const uint mm = 4294967295;

int main()
{
    int n, k;
    scanf("%d %d\n", &n, &k);
    
    for (int i = 0; i < n; i++)
    {
        a[i] = read_ip();
    }
    sort(a, a+n);
    
    for (int g = 31; g >= 0; g--)
    {
        uint cmm = mm << g;
        int curr = 0;
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (j+1 < n && ((a[j+1]&cmm) == (a[j]&cmm))) j++;
            i = j;
            curr++;
        }
        if (curr == k)
        {
            write_ip(cmm);
            return 0;
        }
        else if (curr > k)
        {
            break;
        }
    }
    
    printf("-1");
    return 0;
}