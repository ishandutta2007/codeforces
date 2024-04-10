#include<bits/stdc++.h>

using namespace std;

const int maxN = 2e6 + 100;
int ap[maxN], a[maxN], f[maxN], N;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests, testId = 0;
scanf ("%d", &tests);
while (tests --)
{
    //printf ("Case #%d: ", ++testId);
    scanf ("%d", &N);
    for (int i=1; i<=N; i++)
        scanf ("%d", &a[i]), f[a[i]] ++;
    vector<int> ans;
    int curr = 0, lst = 0;
    for (int i=1; i<=N; i++)
    {
        ap[a[i]] = 1, f[a[i]] --;
        while (ap[curr]) curr ++;
        if (f[curr] == 0)
        {
            ans.push_back(curr);
            for (int j=lst + 1; j<=i; j++)
                ap[a[j]] = 0;
            lst = i, curr = 0;
        }
    }
    printf("%d\n", ans.size());
    for(auto it:ans)
        printf("%d ", it);
    printf("\n");

    for (int i=0; i<=N + 1; i++)
        ap[i] = f[i] = 0;
}

return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/