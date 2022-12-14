#include <iostream>
#include <math.h>

using namespace std;

int sp[5][100000][(int)log2(100000) + 1];
int n, m, k;

int maxx(int D, int l, int r)
{
    int h = log2(r - l + 1);
    return max(sp[D][l][h], sp[D][r - (1 << h) + 1][h]);
}

bool f(int mid)
{
    if(mid == 0)
        return true;
    for(int i = 0; i + mid <= n; ++i)
    {
        //max [D][i]..[D][i + mid - 1]
        bool st = true;
        int kk = k;
        for(int D = 0; D < m; ++D)
        {
            int M = maxx(D, i, i + mid - 1);
            if(M > kk)
            {
                st = false;
                break;
            }
            kk -= M;
        }
        if(st)
            return true;
    }
    return false;
}

void ans(int mid)
{
    if(mid == 0)
    {
        for(int j = 0; j < m; ++j)
            cout << 0 << " ";
        return;
    }
    int opt[m];
    int nonopt[m];
    int curmin = k + 1;
    for(int i = 0; i + mid <= n; ++i)
    {
        //max [D][i]..[D][i + mid - 1]
        int kk = k;
        for(int D = 0; D < m; ++D)
        {
            int M = maxx(D, i, i + mid - 1);
            nonopt[D] = M;
            if(M > kk)
            {
                kk -= M;
                break;
            }
            kk -= M;
        }
        if(k - kk < curmin)
        {
            curmin = k - kk;
            for(int j = 0; j < m; ++j)
                opt[j] = nonopt[j];
        }
    }
    for(int j = 0; j < m; ++j)
        cout << opt[j] << " ";
}

int main()
{
    cin >> n >> m >> k;
    int a[n][5];
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }
    int H = ceil(log2(n));
    for(int D = 0; D < m; ++D)
    {
        for(int i = 0; i < n; ++i)
        {
            sp[D][i][0] = a[i][D];
        }
        for(int h = 1; h <= H; ++h)
        {
            for(int i = 0; i + (1 << h) <= n; ++i)
            {
                sp[D][i][h] = max(sp[D][i][h - 1], sp[D][i + (1 << (h - 1))][h - 1]);
            }
        }
    }
    int l = 0, r = n;
    while(l != r)
    {
        int mid = (l + r) / 2;
        if(f(mid))
            l = mid + 1;
        else
            r = mid;
    }
    if(f(l))
    {
        //cout << l << endl;
        ans(l);
    }
    else
    {
        //cout << l - 1 << endl;
        ans(l - 1);
    }


    return 0;
}