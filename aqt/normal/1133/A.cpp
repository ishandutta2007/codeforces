#include <bits/stdc++.h>

using namespace std;

int main(){
    int h1, m1, h2, m2;
    scanf("%d:%d", &h1, &m1);
    scanf("%d:%d", &h2, &m2);
    m1 += h1*60;
    m2 += h2*60;
    int mid = (m1+m2)>>1;
    printf("%02d:%02d", mid/60, mid%60);
}