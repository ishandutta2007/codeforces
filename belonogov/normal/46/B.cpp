#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

const int q1[5] = {1, 2, 3, 4, 5};
const int q2[5] = {2, 3, 1, 4, 5};
const int q3[5] = {3, 4, 2, 5, 1};
const int q4[5] = {4, 5, 3, 2, 1};
const int q5[5] = {5, 4, 3, 2, 1};

const string q[5] = {"S", "M", "L", "XL", "XXL"};
int a[1000];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    for (int i = 1; i <= 5; i++)
        scanf("%d", &a[i]);
    int n;
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++)
    {
        int num = 0;
        cin >> s;
        for (int j = 0; j < 5; j++)
        {
            if (s == q[j]) num = j;
        }
        if (num == 0)
        {
            for (int j = 0; j < 5; j++)
            {
                if (a[q1[j]])
                {
                    a[q1[j]]--;
                    cout << q[q1[j] - 1];
                    printf("\n");
                    break;
                }
            }
        }
        if (num == 1)
        {
            for (int j = 0; j < 5; j++)
            {
                if (a[q2[j]])
                {
                    a[q2[j]]--;
                    cout << q[q2[j] - 1];
                    printf("\n");
                    break;
                }
            }
        }
        if (num == 2)
        {
            for (int j = 0; j < 5; j++)
            {
                if (a[q3[j]])
                {
                    a[q3[j]]--;
                    cout << q[q3[j] - 1];
                    printf("\n");
                    break;
                }
            }
        }
        if (num == 3)
        {
            for (int j = 0; j < 5; j++)
            {
                if (a[q4[j]])
                {
                    a[q4[j]]--;
                    cout << q[q4[j] - 1];
                    printf("\n");
                    break;
                }
            }
        }
        if (num == 4)
        {
            for (int j = 0; j < 5; j++)
            {
                if (a[q5[j]])
                {
                    a[q5[j]]--;
                    cout << q[q5[j] - 1];
                    printf("\n");
                    break;
                }
            }
        }
    }
}