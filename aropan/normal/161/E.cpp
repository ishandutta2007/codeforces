#include <cstdio>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

#define div mdiv
#define mod mmod

const int MAXF = 100000;
const int MAXL = 10;
const int MAXN = 6;

int f[MAXF];
int answer[MAXF];
vector <int> v[6][6][MAXF];
int l[MAXF];
int n, m;
int ans = 0;
int a[MAXN][MAXN];
int mod[MAXF], div[MAXF];

inline void put(int ind, int x)
{
    for (int i = n; i >= ind; i--)
    {
        a[i][ind] = a[ind][i] = mod[x];
        x = div[x];
    }
}

void rec(int ind)
{
    if (ind == n)
    {
/*
        for (int i = 1; i <= n; i++, printf("\n"))
            for (int j = 1; j <= n; j++)
                printf("%d", a[i][j]);
        printf("\n");
//*/
        ans++;
        return;
    }

    int x = 0;
    for (int i = 1; i <= ind; i++)
        (x *= 10) += a[i][ind + 1];

    for (int i = 0; i < (int)v[n][ind][x].size(); i++)
    {
        put(ind + 1, v[n][ind][x][i]);
        rec(ind + 1);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    for (int i = 0; i < MAXF; i++)
        answer[i] = -1;

    for (int i = 1; i < MAXF; i++)
        l[i] = l[i / 10] + 1;

    for (int i = 0; i < MAXF; i++)
    {
        div[i] = i / 10;
        mod[i] = i % 10;
    }        

    for (int i = 2; i * i < MAXF; i++)
        if (!f[i])
            for (int j = i * i; j < MAXF; j += i)
                f[j] = true;

    for (int i = 2; i < MAXF; i++)
        if (!f[i])
        {
            for (int j = l[i]; j <= 5; j++)
            {
                char s[MAXL], format[MAXL];
                sprintf(format, "%%0%dd", j);
                sprintf(s, format, i);

                int x = 0;
                for (int k = 0; k < j; k++)
                {
                    (x *= 10) += s[k] - '0';
                    v[j][k + 1][x].push_back(i);
                }
            }
//            printf("%d\n", i);
        }
    int t;
    scanf("%d", &t);
//    t = 30;
//    srand(time(NULL));
//    int res = 0;
//    int answer = 0;
    while (t--)
    {
        int p;
        scanf("%d", &p);
//        p = rand() % 100000;
        if (answer[p] == -1)
        {
            m = p;
            n = 0;
            do n++; while (m = div[m]);
            ans = 0;
            put(1, p);
            rec(1);
            answer[p] = ans;
        }
        printf("%d\n", answer[p]);
/*
        if (ans > res)
        {
            res = ans;
            answer = p;
        }
//*/
    }
//    printf("%d %d\n", answer, res);
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}