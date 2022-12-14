#include <bits/stdc++.h>
using namespace std;
long long H, L;
double dep;
int main()
{
    cin >> H >> L;
    dep=(double)(H*H+L*L)/(2*H);
    dep=dep-(double)H;
    printf("%.16lf", dep);
}