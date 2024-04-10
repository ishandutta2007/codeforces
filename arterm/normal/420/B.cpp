#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define M 200100

int n, m, a[M];

bool u[M], t[M], d[M];

void read(void){
    cin >> n >> m;
    char ch;
    int x;
    for (int i = 0; i < m; ++i){
        cin >> ch >> x;
        a[i] = x;
        t[i] = ch == '+';
    }
}

void kill(void){
    
    int s = 0;
    for (int i = 0; i < m; ++i){
        if (t[i])
            d[a[i]] = 1;
        else{
            if (!d[a[i]])
                ++s;
            d[a[i]] = 0;
        }
    }

    for (int i = 0; i < m; ++i){
        
        if (t[i]){
            if ((i>0 && a[i - 1] != a[i]) || s>0)
                u[a[i]] = 1;
        }

        if (t[i])
            ++s;
        else
            --s;


        if (!t[i]){
            if (s > 0 || (i+1<m && a[i+1]!=a[i]))
                u[a[i]] = 1;
        }

    }
}

void write(void){
    int m = 0;

    for (int i = 1; i <= n; ++i)
    if (!u[i])
        ++m;

    cout << m << "\n";
    for (int i = 1; i <= n; ++i)
    if (!u[i])
        cout << i << " ";
    cout << "\n";
}

int main(){
#ifdef GORILLA
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    read();
    kill();
    write();

    return 0;
}