#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
typedef long long int64;
typedef long double ld;

const int inf=2000000000;
const ld eps=1e-07;

char a[10][500];
int b[10][500];

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
        int n;
    scanf("%d",&n);
    if (n %2==0){
        char c[3];
        int tek=0;
        c[0]='a';
        c[1]='b';
        for (int i=0;i<n;){
            a[0][i]=a[0][i+1]=c[tek];
            tek=!tek;
            i+=2;
        }
        c[0]='x';
        c[1]='y';
        for (int i=0;i<n;){
            a[3][i]=a[3][i+1]=c[tek];
            tek=!tek;
            i+=2;
        }
        
        c[0]='c';
        c[1]='d';
        for (int i=1;i<n-1;){
            a[1][i]=a[1][i+1]=c[tek];
            tek=!tek;
            i+=2;
        }
        c[0]='h';
        c[1]='i';
        for (int i=1;i<n-1;){
            a[2][i]=a[2][i+1]=c[tek];
            tek=!tek;
            i+=2;
        }
        a[1][0]=a[2][0]='e';
        a[1][n-1]=a[2][n-1]='f';
    }
    else {
        char c[3];
        int tek=0;
        c[0]='a';
        c[1]='b';
        for (int i=0;i<n-1;){
            a[0][i]=a[0][i+1]=c[tek];
            tek=!tek;
            i+=2;
        }
        c[0]='c';
        c[1]='d';
        for (int i=0;i<n-1;){
            a[1][i]=a[1][i+1]=c[tek];
            tek=!tek;
            i+=2;
        }
        a[0][n-1]=a[1][n-1]='e';
        a[2][0]=a[3][0]='f';
        c[0]='g';
        c[1]='h';
        for (int i=1;i<n;){
            a[2][i]=a[2][i+1]=c[tek];
            tek=!tek;
            i+=2;
        }
        c[0]='x';
        c[1]='y';
        for (int i=1;i<n;){
            a[3][i]=a[3][i+1]=c[tek];
            tek=!tek;
            i+=2;
        }
    }
    for (int i=0;i<4;++i){
        for(int j=0;j<n;++j)
            printf("%c",a[i][j]);
        printf("\n");
    }
    return 0;
}