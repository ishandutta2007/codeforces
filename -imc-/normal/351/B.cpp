#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;

const int maxN = 3050;
int a[maxN];
int n;

int countInversions()
{
    int inv = 0;
    
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[i])
                inv++;
            
    return inv;
}

double pFirst[maxN], pSecond[maxN];
int maxInv;

float dumbCalc (int inv)
{
    double* p = pFirst, *pNext = pSecond;    
    
    double answer = 0;
    
    for (int i = 0; i < maxInv; i++)
        p[i] = 0;
    
    p[inv] = 1;
       
    for (int turn = 1; turn < 400; turn++)
    {
        for (int i = 0; i < maxInv; i++)
            pNext[i] = 0;
        
        if (turn % 2 == 1)
        {
            for (int t = 1; t < maxInv; t++)
                pNext[t - 1] = p[t];
        }
        else
        {
            for (int t = 1; t < maxInv; t++)
            {
                pNext[t - 1] += p[t] / 2;
                if (t != maxInv - 1)
                    pNext[t + 1] += p[t] / 2;
                else
                    pNext[t - 1] += p[t] / 2;
            }
        }
        
        swap (p, pNext);
        
        answer += p[0] * turn;
        //for (int i = 0; i < n; i++)
        //    printf ("prob %d is %f\n", i, (float)p[i]);
    }
    
    //cout << fixed << setprecision (10) << answer << endl;    
    return answer;
}

double clever (long long t)
{
    return (t % 2 == 0 ? 2 * t : 2 * t - 1);
}

int main()
{
    scanf ("%d", &n);
    maxInv = n * (n + 1) / 2;
    
    for (int i = 0; i < n; i++)
        scanf ("%d", &a[i]);
    
    int inv = countInversions();
    
    cout << fixed << setprecision (12) << clever (inv) << endl;
    return 0;
    
    printf ("%d inversions\n", inv);
    
    //dumbCalc();
    
    for (int i = 0; i < maxInv; i++)
        printf ("%d: %f %f\n", i, (float)dumbCalc (i), (float) clever (i));
        
    return 0;
}