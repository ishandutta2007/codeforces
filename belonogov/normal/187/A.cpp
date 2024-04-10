#include <iostream>
#include <cstdio>

using namespace std;
#define forn(i, n) for(i = 0; i < n; i++)
#define forab(i, a, b) for(i = a; i < b; i++)
#define forba(i, b, a) for(i = b; i > a; i--)

typedef long long ll;
typedef double db;

int a[200000];
int b[200000];

int main(){
    int i, n, uk;
    cin >> n;
    forn(i, n)
        cin >> a[i];
    forn(i, n)
        cin >> b[i];
    uk = 0;
    forn(i, n){
        while (b[uk] != a[i] && uk < n)
            uk++;
        if (uk == n){
            cout << n - i;
            return 0;
        }
    }
    cout << 0;  
    return 0;

}