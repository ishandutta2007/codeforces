#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++){
        scanf("%d", &temp);
        if (temp % 2 == 0)
            printf ("1 \n");
        else
            printf ("0 \n");}
    return 0;
}