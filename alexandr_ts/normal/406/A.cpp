#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;

int a[2000][2000];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n;
    cin >> n;
    ll qua = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i == j)
                qua += a[i][j];
    qua %= 2;
    int k;
    cin >> k;
    int temp;
    int temp2;
    for(int i = 0; i < k; i++)
    {
        scanf("%d", &temp);
        if(temp == 3)
            printf("%d", qua);
        else
            if(temp == 2)
            {
                scanf("%d", &temp2);
                qua = qua xor 1;
            }
        else
            if(temp == 1)
            {
                scanf("%d", &temp2);
                qua = qua xor 1;
            }
    }
    return 0;
}