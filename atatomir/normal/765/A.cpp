#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

int n;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    if (n % 2)
        printf("contest");
    else
        printf("home");


    return 0;
}