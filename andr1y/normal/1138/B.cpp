#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> aa, bb, cc, dd;
const int N = 5e3 + 10;
int n,na,nb,nc,nd;
int a[N], c[N];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%1d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%1d", &c[i]);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0 && c[i] == 0)
            na++, aa.push_back(i+1);
        else if (a[i] == 0 && c[i] == 1)
            nb++, bb.push_back(i+1);
        else if (a[i] == 1 && c[i] == 0)
            nc++, cc.push_back(i+1);
        else
            nd++, dd.push_back(i+1);
    }
    for (int a = 0; a <= na; a++)
    {
        for (int b = 0; b <= nb; b++)
        {
            int c =n-nb-nd-2*a-b;
            if (c >= 0 && c <= nc)
            {
                int d = nb+nd-n/2+a;
                if (d >= 0 && d <= nd)
                {
                    //cout << a << b << c << d << endl;
                    for (int i = 0; i < a; i++)
                        printf("%d ", aa[i]);
                    for (int i = 0; i < b; i++)
                        printf("%d ", bb[i]);
                    for (int i = 0; i < c; i++)
                        printf("%d ", cc[i]);
                    for (int i = 0; i < d; i++)
                        printf("%d ", dd[i]);
                    printf("\n");
                    return 0;
                }

            }
        }
    }
    printf("-1\n");
    return 0;
}