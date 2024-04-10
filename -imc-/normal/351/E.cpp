#include <cstdio>
#include <algorithm>

using namespace std;

const int maxN = 2050;
int a[maxN];

int main()
{
    int nNumbers;
    scanf ("%d", &nNumbers);
    
    for (int i = 0; i < nNumbers; i++)
    {
        scanf ("%d", &a[i]);
        a[i] = abs (a[i]);
    }
    
    int answer = 0;
    for (int i = 0; i < nNumbers; i++)
    {
        int delta = 0;
        for (int j = i + 1; j < nNumbers; j++)
            if (a[j] < a[i])
                delta++;
            
        answer += delta;
        //printf ("+= anyway %d\n", delta);
            
        for (int j = 0; j < i; j++)
            if (a[j] < a[i])
                delta--;
            
        if (delta > 0)
        {
            answer -= delta;
            //printf ("put %d (-%d)\n", -a[i], delta);
        }
        else
        {
            //printf ("put %d\n", a[i]);
        }
    }
    
    printf ("%d\n", answer);
    
    return 0;
}