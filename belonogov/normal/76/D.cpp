#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 100;
const int inf = 1e9;

int a[maxn];
int b[maxn];
int p[maxn];
int x[maxn];
int y[maxn];
int r[maxn];

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    unsigned long long A, B, X = 0, Y = 0;
    int n = 64;
    cin >> A >> B;
//  cerr << (1ull << 63) << endl;
    for (int i = 0; i < n; i++, A /= 2, B /= 2){
        a[i] = A % 2;
        b[i] = B % 2;
    }
    if (a[0] != b[0]){
        cout << -1 << endl;
        return 0;       
    }
    
    for (int i = 0; i < n; i++)
        p[i] = a[i + 1] != b[i + 1];
    
    for (int i = 0; i < n; i++){
        if (b[i] == 0){
            if (p[i] == 1)
                x[i] = y[i] = 1;
            else
                x[i] = y[i] = 0;
        }
        else{
            x[i] = 0;
            y[i] = 1;
        }
    }
    bool flag = 1;
    int d = 0, t;
    for (int i = 0; i < n + 1; i++){
        t = d + x[i] + y[i];
        r[i] = t % 2;
        d = t / 2;
        flag &= r[i] == a[i];
    }
    if (!flag){
        cout << -1 << endl;
        return 0;   
    }
    for (int i = n - 1; i >= 0; i--){
        X = X * 2 + x[i];
        Y = Y * 2 + y[i];
        //      X = X + (x[i] << i);
//      Y = Y + (y[i] << i);        
    }
    cout << X << " "  << Y << endl;
    
    
 
    return 0;
}