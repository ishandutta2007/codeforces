#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int n, a[100000][3], rez[100000];

int qsort(int l, int r)
{
    int i, j, m, q;
    i = l;
    j = r;
    m = a[(l + r) / 2][0];
    while (i <= j)
    {
        while (a[i][0] < m){
            i++;}
        while (a[j][0] > m){
            j--;}
        if (i <= j){
            q = a[i][0];
            a[i][0] = a[j][0];
            a[j][0] = q;
            q = a[i][1];
            a[i][1] = a[j][1];
            a[j][1] = q;
            q = a[i][2];
            a[i][2] = a[j][2];
            a[j][2] = q;
            i++;
            j--;
        }
    }

    if (i < r) qsort(i, r);
    if (l < j) qsort(l, j);
    return 0;
}
int bin(int k)
{
    int l, r;
    l = 0;
    r = n;
    while (r - l > 1)
    {
        if (a[(r + l) / 2][0] > k)
            r = (r + l) / 2;
        else
            l = (r + l) / 2;
    }
    return l;

}

int main()
{
   int x1, i, m, x, y, k;
    cin >> n;
    for (i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1];
        rez[i] = -1;
        a[i][2] = i;
    }
    qsort(0, n - 1);
    cin >> m;
    for (i = 0; i < m; i++)
    {
        cin >> x >> y;
        k = bin(x);
        x1 = x - a[k][0];
        if (a[k][1] * a[k][1] >= x1 * x1 + y * y && rez[k] == -1)
        {
            rez[k] = i + 1;
        }
        if (k < n - 1)
        {
            k++;
            x1 = x - a[k][0];
            if (a[k][1] * a[k][1] >= x1 * x1 + y * y && rez[k] == -1)
            {
                rez[k] = i + 1;
            }

        }
    }
    int kol;
    kol = n;
    for (i = 0; i < n; i++)
    {
        if (rez[i] == -1)
          kol--;
    }
    cout << kol << endl;
    int ans[100000];
    for (i = 0; i < n; i++)
    {
        ans[a[i][2]] = rez[i];
    }
    for (i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}