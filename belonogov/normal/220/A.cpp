#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define forab(i, a, b) for(int i = a; i < b; i++)
#define forba(i, b, a) for(int i = b; i > a; i--)

typedef long long ll;
typedef double db;

const int maxn = 2e5;
int a[maxn];
int b[maxn];

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, cnt;
    cin >> n;
    forn(i, n){     
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a + n);
    cnt = 0;
    forn(i, n)
        if (a[i] != b[i])
            cnt++;
    if (cnt <= 2)
        cout << "YES";
    else
        cout << "NO";
    return 0;

}