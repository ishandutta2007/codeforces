#include <bits/stdc++.h>
 
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
 
#define debug(...) {fprintf(stderr, __VA_ARGS__);}
 
const int N = 2e5+7;
 
char str[N];
int n, t;
int good[N];
char ip[N];
 
bool sum () {
    int m = strlen(ip);
 
    bool cr = 1;
    m--;
    while (m >= 0) {
        if (!cr) break;
        cr = 0;
        if (ip[m] == '9') {
            cr = 1;
            ip[m] = '0';
        } else {
            ip[m]++;
        }
        m--;
    }
    return cr;
}
 
int main () {
    scanf("%d %d", &n, &t);
    scanf(" %[0-9].%s", ip, str);
 
    n = strlen(str);
 
    good[n] = t+1;
    int res = n;
    for (int i = n-1; i >= 0; i--) {
        if (str[i] >= '5')
            good[i] = 1;
        else if (str[i] == '4')
            good[i] = good[i+1] + 1;
        else
            good[i] = t+1;
 
        if (good[i] <= t) res = i;
    }
    
    if (res == n) {
        printf("%s.%s\n", ip, str);
    } else {
        bool cr = 0;
        int stp = n;
        for (int i = res + good[res] - 1; i >= 0; i--) {
            if (cr) str[i]++;
            cr = 0;
            if (t && str[i] >= '5') {
                cr = 1;
                t--;
                stp = i;
            }
        }
        assert(stp == res);
        str[stp] = 0;
        if (cr && sum()) printf("1");
        printf("%s", ip);
		if (stp) printf(".");
		printf("%s\n", str);
    }
}