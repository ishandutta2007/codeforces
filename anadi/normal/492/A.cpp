#include<iostream>
#include<vector>
#include<cstdio>
#include <cmath>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int suma=0;
    for(int i=1;i<=n;++i){
        suma+=i*(i+1)/2;
        //printf("%d\n", suma);
        if(suma>n){
            suma=i-1;
            break;
        }
    }
    printf("%d\n", suma);
    return 0;
}