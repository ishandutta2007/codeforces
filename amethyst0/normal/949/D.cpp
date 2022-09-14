#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <ctime>

#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>
#define ld long double

using namespace std;

const int maxn = (int)1e5 + 10;

int v[maxn];

int n, d, b;

int a[maxn];

bool check(int x) {
    int l = x;
    int r = n - 1 - x;
    int m = n / 2;
    
    int pos = 0;
    
    memcpy(a, v, sizeof v);
    
    for (int i = l; i <= m; i++) {
        ll dst = (ll)d * min(i + 1, n - i);
        
        if (pos < i - dst) {
            pos = i - dst;
        }
        
        while (a[i] < b) {
            if (pos > i + dst || pos == n) {
                return false;
            }
            
            if (pos == i) {
                pos++;
                continue;
            }
            
            if (a[pos] == 0) {
                pos++;
                continue;
            }
            
            if (pos < i) {
                int cnt = a[pos];
                
                if (pos >= l) {
                    cnt -= b;
                }
                
                if (cnt >= b - a[i]) {
                    a[pos] -= b - a[i];
                    a[i] = b;
                    break;
                } else {
                    a[pos] -= cnt;
                    a[i] += cnt;
                    pos++;
                    continue;
                }
            } else {
                int cnt = a[pos];
                
                if (cnt >= b - a[i]) {
                    a[pos] -= b - a[i];
                    a[i] = b;
                    break;
                } else {
                    a[pos] -= cnt;
                    a[i] += cnt;
                    pos++;
                    continue;
                }
            }
        }
    }
    
    reverse(a, a + n);
    m = n - m - 1;
    swap(l, r);
    l = n - l - 1;
    r = n - r - 1;
    
    pos = 0;
    
    for (int i = l; i < m; i++) {
        ll dst = (ll)d * min(i + 1, n - i);
        
        if (pos < i - dst) {
            pos = i - dst;
        }
        
        while (a[i] < b) {
            if (pos > i + dst || pos == n) {
                return false;
            }
            
            if (pos == i) {
                pos++;
                continue;
            }
            
            if (a[pos] == 0) {
                pos++;
                continue;
            }
            
            if (pos < i) {
                int cnt = a[pos];
                
                if (pos >= l) {
                    cnt -= b;
                }
                
                if (cnt >= b - a[i]) {
                    a[pos] -= b - a[i];
                    a[i] = b;
                    break;
                } else {
                    a[pos] -= cnt;
                    a[i] += cnt;
                    pos++;
                    continue;
                }
            } else {
                int cnt = a[pos];
                
                if (m <= pos && pos <= r) {
                    cnt -= b;
                }
                
                if (cnt >= b - a[i]) {
                    a[pos] -= b - a[i];
                    a[i] = b;
                    break;
                } else {
                    a[pos] -= cnt;
                    a[i] += cnt;
                    pos++;
                    continue;
                }
            }
        }
    }
    
    return true;
}

int main() {
    cin >> n >> d >> b;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        //v[i] = 0;
    }
    
    //v[n - 1] = n * b;
    
    int l = 0, r = n / 2;
    
    while (l != r) {
        int m = (l + r) >> 1;
        
        if (check(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    
    cout << l << endl;
    return 0;
}