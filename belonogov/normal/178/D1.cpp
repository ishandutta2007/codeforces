#include <iostream>
#include <cstdio>

using namespace std;
#define forn(i, n) for(i = 0; i < n; i++)
#define forab(i, a, b) for(i = a; i < b; i++)
#define forba(i, b, a) for(i = b; i > a; i--)

typedef long long ll;
typedef double db;
int a[100];
int b[100];
bool use[100];
int n;

void check(){
    int sum, i, j;
    if (n == 3){
        sum = b[0] + b[1] + b[2];
        if (b[3] + b[4] + b[5] != sum)
            return;
        if (b[6] + b[7] + b[8] != sum)
            return;
        if (b[0] + b[3] + b[6] != sum)
            return;
        if (b[1] + b[4] + b[7] != sum)
            return;
        if (b[2] + b[5] + b[8] != sum)
            return;
        if (b[0] + b[4] + b[8] != sum)
            return;
        if (b[2] + b[4] + b[6] != sum)
            return;
        cout << sum << "\n";
        forn(i, n){
            forn(j, n)
                printf("%d ", b[i * 3 + j]);
            printf("\n");
        }
        exit(0);
    }
    if (n == 2){
        sum = a[0] + a[1];
        if (a[2] + a[3] != sum)
            return;
        if (a[0] + a[2] != sum)
            return;
        if (a[1] + a[3] != sum)
            return;
        if (a[1] + a[2] != sum)
            return;
        if (a[0] + a[3] != sum)
            return;
        cout << sum << "\n";
        printf("%d %d\n", a[0], a[1]);
        printf("%d %d\n", a[2], a[3]);
        exit(0);
    }
    
}

void gen(int k){
    int i;
    if (k >= n * n)
        check();
    
    forn(i, n * n){
        if (! use[i]){
            use[i] = true;
            b[k] = a[i];
            gen(k + 1);
            use[i] = false;
            b[k] = 0;
        }
    }

}


int main(){
    int i;
    cin >> n;
    forn(i, n * n)
        cin >> a[i];
    if (n == 1){
        cout << a[0] << "\n" << a[0];
        return 0;
    }
    gen(0);

    return 0;

}