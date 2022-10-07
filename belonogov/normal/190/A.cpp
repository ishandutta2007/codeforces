#include <iostream>
#include <cstdio>

using namespace std;
#define forn(i, n) for(i = 0; i < n; i++)
#define forab(i, a, b) for(i = a; i < b; i++)
#define forba(i, b, a) for(i = b; i > a; i--)

typedef long long ll;
typedef double db;


int main(){
   int n, m;
    cin >> n >> m;
    if (n == 0 && m != 0){
        cout << "Impossible";
        return 0;
    }
    cout << (n + m) - min(n, m) << " "; 

    if (m != 0) 
        cout << n + m - 1;
    else
        cout << n;
    return 0;

}